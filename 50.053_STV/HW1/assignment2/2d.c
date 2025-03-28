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