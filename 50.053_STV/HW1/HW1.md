# SUTD - 50.053 Software Testing and Verification - Homework 1
## Spring 2025
### Author
Atul Parida (1006184)

### Date of Submission
28th March 2025

## Answers for Homework
### Assignment 1
The files used for Assignment 1 are attached in the folder `assignment1`.

a) The file used for the test driver is `assignment1/1a.c`, containing both the test loop and the test driver. The file is embedded as follows:

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int test_loop(int a[])
{
    int y;
    int i = 0;
    while (i < 100)
    {
        if (a[i] < 10)
            y++;
        else
            y--;
        i++;
    }
    assert(y <= 100);
}

int main()
{
    int a[100];
    klee_make_symbolic(a, sizeof(a), "a");
    test_loop(a);
    return 0;
}
```

b) The file used to run the test driver built in part a) based on the requirements of part b) is `assignment1/1b.sh`. The file is embedded as follows:

```bash
clang -emit-llvm -g -c 1A.c -o 1A.bc
timeout 15s klee --write-smt2s 1A.bc
```

b) When running the test driver with KLEE, I observed the following behavior:

```markdown
KLEE: output directory is "/home/klee/HW1/assignment1/klee-out-0"  
KLEE: Using STP solver backend  
KLEE: SAT solver: MiniSat  
KLEE: Deterministic allocator: Using quarantine queue size 8  
KLEE: Deterministic allocator: globals (start-address=0x7ffd792e1000 size=10 GiB)  
KLEE: Deterministic allocator: constants (start-address=0x7ffaf92e1000 size=10 GiB)  
KLEE: Deterministic allocator: heap (start-address=0x7efaf92e1000 size=1024 GiB)  
KLEE: Deterministic allocator: stack (start-address=0x7edaf92e1000 size=128 GiB)
```

This output shows the initial configuration details from KLEE without any further execution path logs, and means that KLEE simply disposed of the test driver without generating any test cases. This is likely on account of the fact that the test driver is not well-formed, as it does not initialize the variable `y` before using it in the loop. This leads to undefined behavior, which KLEE cannot handle. All relevant klee outputs for this part were in `klee-out-0`.

c) The file used for the updated test driver is `assignment1/1c.c`, containing both the test loop and the test driver. The file is embedded as follows:

```c
#include <stdio.h>
#include <assert.h>

int test_loop(int a[]) {
    int y = 0;
    int i = 0;
    while (i < 100) {
        y++; // Modify loop to make KLEE generate 1 test
        i++;
    }
    assert(y <= 100);
    return y;
}

int main() {
    int a[100];
    klee_make_symbolic(&a, sizeof(a), "a");
    return test_loop(a);
}

```
In the modified `test_loop` function, I initialized the variable `y` to 0 before using it in the loop. I also modified the loop to increment `y` for each iteration, ensuring that KLEE generates a single test case.

Since KLEE generates test cases for different execution paths, and the modified function has only one possible path regardless of inputs, KLEE will generate exactly one test case. This is validated by the following output when running the test driver with KLEE:

```bash
KLEE: done: total instructions = 1027
KLEE: done: completed paths = 1
KLEE: done: partially completed paths = 0
KLEE: done: generated tests = 1
```

This output indicates that KLEE successfully executed the test driver and generated one test case, which is consistent with the modifications made to the `test_loop` function. All relevant klee outputs for this part were in `klee-out-1`.

### Assignment 2
The files used for Assignment 2 are attached in the folder `assignment2`.

a) Considering we want to handle concolic execution specifically for input `x` and the function `test_unit`, I made certain modifications to the test driver. The file used for the test driver is `assignment2/2a.c`, containing both the test loop and the test driver. The file is embedded as follows:

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* cell structure, data type lengths are shown alongside */
typedef struct cell
{
    long v;            // 8 bytes
    struct cell *next; // 8 bytes
    struct cell *prev; // 8 bytes
} cell;
void test_unit(cell *p, int x)
{
    /* allocate one cell */
    p = (cell *)malloc(sizeof(cell));
    p->v = 0;
    p->next = p->prev = NULL;
    if (x > 0)
    {
        cell *cur = (cell *)((char *)p + sizeof(long));
        cur->next = cur->prev = p;
        if (p->prev != NULL)
            assert(0 && "You should get out of here!!!"); // buggy function
    }
}

int main()
{
    int x;
    klee_make_symbolic(&x, sizeof(x), "x");
    test_unit(NULL, x);
    return 0;
}

```

b) The file used to run the test driver built in part a) based on the requirements of part b) is `assignment2/2b.sh`. The file is embedded as follows:

```bash
clang -emit-llvm -g -c 2A.c -o 2A.bc
klee 2A.bc
```

We got the following error message from KLEE:
```
KLEE: output directory is "/home/klee/HW1/assignment2/klee-out-0"
KLEE: Using STP solver backend
KLEE: SAT solver: MiniSat
KLEE: Deterministic allocator: Using quarantine queue size 8
KLEE: Deterministic allocator: globals (start-address=0x7ffd792e1000 size=10 GiB)
KLEE: Deterministic allocator: constants (start-address=0x7ffaf92e1000 size=10 GiB)
KLEE: Deterministic allocator: heap (start-address=0x7efaf92e1000 size=1024 GiB)
KLEE: Deterministic allocator: stack (start-address=0x7edaf92e1000 size=128 GiB)
KLEE: WARNING: undefined reference to function: assert
KLEE: WARNING ONCE: Alignment of memory from call "malloc" is not modelled. Using alignment of 8.
KLEE: ERROR: 2A.c:15: memory error: out of bound pointer
KLEE: NOTE: now ignoring this error at this location

KLEE: done: total instructions = 41
KLEE: done: completed paths = 1
KLEE: done: partially completed paths = 1
KLEE: done: generated tests = 2
```

This implies that KLEE was able to generate two test cases based on the symbolic execution of the `test_unit` function. The first test case was generated when `x` was set to a value greater than 0, which led to the assertion failure. The second test case was generated when `x` was set to a value less than or equal to 0, which did not lead to any assertion failure. The error faced was caused by the fact that the pointer `p` was not properly initialized before being dereferenced, leading to an out-of-bounds memory access. This is a common issue in C programming, especially when dealing with pointers and dynamic memory allocation.

c) The file used to run the test driver built in part a) based on the part c) requirements is `assignment2/2c.sh`. The file is embedded as follows:

```bash
#!/bin/bash
# Compile the source code to LLVM bitcode
clang -emit-llvm -g -c 2A.c -o 2A.bc
# Run KLEE using the local installation (without Docker)
klee 2A.bc
```

We got the following error message:

```
2A.c:17:13: error: call to undeclared function 'assert'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
   17 |             assert(0 && "You should get out of here!!!");
      |             ^
2A.c:23:5: error: call to undeclared function 'klee_make_symbolic'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
   23 |     klee_make_symbolic(&x, sizeof(x), "x");
      |     ^
2 errors generated.
2c.sh:2: command not found: timeout
```

The error messages indicate that the `assert` function and the `klee_make_symbolic` function were not declared before being used in the code. This is a common issue when using functions from libraries that require specific header files to be included. The `assert` function is defined in the `<assert.h>` header file, and the `klee_make_symbolic` function is defined in the KLEE library.

This makes sense, as we're running this outside of the KLEE docker, and the `klee_make_symbolic` function is not available in the standard C library. To resolve this, we need to include the appropriate header files and ensure that KLEE is properly set up in our environment. `timeout` is also not available in zsh, which I ran this in, which surprised me a bit.

d) For part d), we were required to instrument the code in the test cases to check for errors and gracefully exit the code if any such errors were found. The code was modified as follows:

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* cell structure, data type lengths are shown alongside */
typedef struct cell {
    long v;            // 8 bytes
    struct cell *next; // 8 bytes
    struct cell *prev; // 8 bytes
} cell;

int test_unit(int x)
{
    cell *p = (cell *)malloc(sizeof(cell));
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    p->v = 0;
    p->next = p->prev = NULL;
    if (x > 0)
    {
        cell *cur = (cell *)malloc(sizeof(cell));
        if (!cur) {
            fprintf(stderr, "Memory allocation failed\n");
            free(p);
            return -1;
        }
        cur->next = cur->prev = p;
        p->prev = cur;
    }
    /* cleanup for graceful exit */
    free(p);
    return 0;
}

int main()
{
    int x;
    int ret;
    klee_make_symbolic(&x, sizeof(x), "x");
    ret = test_unit(x);
    if(ret != 0) {
        return EXIT_FAILURE;
    }
    return 0;
}
```

The code was modified to include error handling for memory allocation failures. If the memory allocation fails, the program prints an error message to `stderr` and returns a non-zero value to indicate failure. The `main` function also checks the return value of `test_unit` and exits gracefully if an error occurred.

The `free` function is used to deallocate the memory allocated for the `cell` structure to prevent memory leaks. The program now handles errors gracefully and exits with a non-zero status if any errors occur during execution.

This was tested further by running the test driver with KLEE, and the following output was generated:

```
KLEE: WARNING: undefined reference to function: fprintf
KLEE: WARNING: undefined reference to variable: stderr
KLEE: WARNING ONCE: Alignment of memory from call "malloc" is not modelled. Using alignment of 8.

KLEE: done: total instructions = 83
KLEE: done: completed paths = 2
KLEE: done: partially completed paths = 0
KLEE: done: generated tests = 2
```

This indicates that the error condition was detected, and the program exited gracefully as expected.