# Run KLEE for 15 seconds and force terminate if needed
clang -emit-llvm -g -c 1A.c -o 1A.bc
timeout 15s klee --write-smt2s 1A.bc