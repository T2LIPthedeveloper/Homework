#include<stdio.h>
#include<stdlib.h>

int int_divide_by_2_power_n(int val, int n) {
    return val >> n;
}

void print_bits(char c) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int val = atoi(argv[1]);
    int n = atoi(argv[2]);
    int result = int_divide_by_2_power_n(val, n);
    printf("val = %d, n = %d, result = %d\n", val, n, result);
    print_bits(val);
    print_bits(result);
    return 0;
}