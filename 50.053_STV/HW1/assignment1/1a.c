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