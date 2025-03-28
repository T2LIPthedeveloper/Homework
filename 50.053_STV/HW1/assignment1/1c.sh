# Run KLEE for 15 seconds and force terminate if needed
clang -emit-llvm -g -c 1C.c -o 1C.bc
timeout 15s klee --write-smt2s 1C.bc