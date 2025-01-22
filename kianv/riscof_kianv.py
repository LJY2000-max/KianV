import os
import logging
import subprocess
import shutil
import re
import shlex
from string import Template
import sys

import riscof.utils as utils
from riscof.pluginTemplate import pluginTemplate

logger = logging.getLogger()

class kianv(pluginTemplate):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        config = kwargs.get('config')

        # Check if required config fields exist
        if config is None:
            logger.error("Config node for kianv not found in config.ini")
            raise SystemExit(1)
        if 'pluginpath' not in config:
            logger.error("'pluginpath' not found in config.")
            raise SystemExit(1)
        if 'ispec' not in config or 'pspec' not in config:
            logger.error("ISA/Platform specs not found in config.")
            raise SystemExit(1)

        self.pluginpath = os.path.abspath(config['pluginpath'])
        self.isa_spec = os.path.abspath(config['ispec'])
        self.platform_spec = os.path.abspath(config['pspec'])
        
        # Setup DUT with paths
        self.dut_exe = os.path.join(self.pluginpath, 'kianv_sim')
        self.num_jobs = str(config.get('jobs', 1))
        self.make = config.get('make', 'make')
        
        # Check the target_run variable
        if 'target_run' in config and config['target_run']=='0':
            self.target_run = False
        else:
            self.target_run = True

    def initialise(self, suite, work_dir, env):
        self.work_dir = work_dir
        self.suite_dir = suite
        """
        self.compile_cmd = 'riscv32-unknown-elf-gcc -march={0} ' \
                         '-static -mcmodel=medany -fvisibility=hidden ' \
                         '-nostdlib -nostartfiles -g -T ' + self.pluginpath + \
                         '/env/link.ld -I ' + self.pluginpath + \
                         '/env -I ' + env + ' {2} -o {3} {4}'
        """
        # 使用 RISCV64 工具鏈但指定 32 位元架構和 ABI
        # -march=rv32gc: 支援 RV32 基本指令集 (G) 和壓縮指令集 (C)
        # -mabi=ilp32: 使用 32 位元 Integer, Long, 和 Pointer ABI
        self.compile_cmd = f'{os.getenv("RISCV_PREFIX", "riscv64-unknown-elf-")}gcc '\
                        f'-march={{0}} -mabi=ilp32 '\
                        f'-static -mcmodel=medany -fvisibility=hidden '\
                        f'-nostdlib -nostartfiles -g '\
                        f'-T {self.pluginpath}/env/link.ld '\
                        f'-I {self.pluginpath}/env '\
                        f'-I {env} {{2}} -o {{3}} {{4}}'

    """
    def build(self, isa_yaml, platform_yaml):
        ispec = utils.load_yaml(isa_yaml)['hart0']
        self.xlen = '32'  # 強制使用 32 位元模式
        
        # 在建置開始時檢查工具鏈
        logger.debug("Checking toolchain availability")
        toolchain_check = utils.shellCommand('riscv64-unknown-elf-gcc --version').run()
        if toolchain_check.returncode != 0:
            logger.error("RISC-V toolchain not found. Please install riscv64-unknown-elf-gcc")
            raise SystemExit(1)

        # 建置模擬器
        logger.debug("Building KianV simulator")
        build_cmd = f'cd {self.pluginpath} && make clean && make'
        build_result = utils.shellCommand(build_cmd).run()
        
        if build_result.returncode != 0:
            logger.error("Failed to build KianV simulator")
            raise SystemExit(1)
    """
    def build(self, isa_yaml, platform_yaml):
        ispec = utils.load_yaml(isa_yaml)['hart0']
        self.xlen = '32'  # 強制使用 32 位元模式
        
        # 在建置開始時檢查工具鏈
        logger.debug("Checking toolchain availability")
        try:
            result = subprocess.run(['riscv64-unknown-elf-gcc', '--version'], 
                                    capture_output=True, text=True)
            if result.returncode != 0:
                logger.error("RISC-V toolchain not found. Please install riscv64-unknown-elf-gcc")
                raise SystemExit(1)
        except FileNotFoundError:
            logger.error("RISC-V toolchain executable not found. Please install riscv64-unknown-elf-gcc")
            raise SystemExit(1)

        # 建置模擬器
        logger.debug("Building KianV simulator")
        try:
            build_result = subprocess.run(
                f'cd {self.pluginpath} && make clean && make', 
                shell=True, 
                capture_output=True, 
                text=True
            )
            
            if build_result.returncode != 0:
                logger.error(f"Failed to build KianV simulator: {build_result.stderr}")
                raise SystemExit(1)
        except Exception as e:
            logger.error(f"Error during KianV simulator build: {e}")
            raise SystemExit(1)

    def runTests(self, testList):
        if not os.path.exists(self.work_dir):
            os.makedirs(self.work_dir)

        for testname in testList:
            testentry = testList[testname]
            test = testentry['test_path']
            test_dir = testentry['work_dir']

            if not os.path.exists(test_dir):
                os.makedirs(test_dir)

            # Create a symbolic link to env folder
            os.system('ln -sf ' + self.pluginpath + '/env/link.ld ' + test_dir + '/link.ld')

            # Compile the test
            elf = 'my.elf'
            compile_macros = ' -D' + " -D".join(testentry['macros'])
            marchstr = testentry['isa'].lower()
            
            cmd = self.compile_cmd.format(marchstr, self.xlen, test, 
                                       os.path.join(test_dir, elf), compile_macros)
            utils.shellCommand(cmd).run(cwd=test_dir)

            if self.target_run:
                # Run the test on DUT
                sig_file = os.path.join(test_dir, self.name[:-1] + ".signature")
                sim_cmd = f'{self.dut_exe} {os.path.join(test_dir, elf)} {sig_file}'
                utils.shellCommand(sim_cmd).run(cwd=test_dir)

        # If target runs are not required, exit here
        if not self.target_run:
            raise SystemExit
        
    def detect_toolchain_prefix(self):
        """
        自動檢測可用的 RISC-V 工具鏈前綴
        優先使用 riscv-none-elf- 前綴
        """
        import shutil

        # 優先檢測 riscv-none-elf 工具鏈
        preferred_prefixes = [
            'riscv-none-elf-',      # 優先選擇
            'riscv64-elf-',         
            'riscv64-unknown-elf-', 
            'riscv32-unknown-elf-'
        ]

        for prefix in preferred_prefixes:
            gcc = shutil.which(f'{prefix}gcc')
            objdump = shutil.which(f'{prefix}objdump')
            if gcc and objdump:
                logger.info(f"Using toolchain prefix: {prefix}")
                return prefix

        logger.error("No suitable RISC-V toolchain found.")
        raise SystemExit(1)