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
