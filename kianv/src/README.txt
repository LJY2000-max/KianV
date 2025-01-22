在fetch_stage.sv、decode_stage.sv檔案出現不存在的模組呼叫，該模組是dflop。找到了，dflop定義在design_elements.sv。
store_alignment.sv 中 wmask  = 4'b0000;，在原始檔案是 wmask  = 0;。