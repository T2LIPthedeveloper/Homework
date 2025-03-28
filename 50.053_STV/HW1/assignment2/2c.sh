clang -emit-llvm -g -c 2A.c -o 2A.bc
klee --write-smt2s 2A.bc
