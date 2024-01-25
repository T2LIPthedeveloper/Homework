#include<stdio.h>
#include<stdbool.h>

/* Exercise 1 */
int fact_loop(int n) {
    int result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int fact_rec(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact_rec(n - 1);
}

/* Exercise 2 */
int fibo(int n) {
    int i = 0;
    int j = 1;
    int k = 0;
    if (n == 1) {
        printf("%d\n", i);
        return 0;
    }
    else if (n == 2) {
        printf("%d, %d\n", i, j);
        return 0;
    }
    else {
        int count = 3;
        printf("%d, %d, ", i, j);
        do {
            k = i + j;
            printf("%d, ", k);
            i = j;
            j = k;
            count++;
        } while (count <= n);
        printf("\n");
    }
    return 0;
}

/* Exercise 3 */
int is_prime(int n) {
    int i;
    for (i = 2; i <= (n/2); i++) {
        if (n%i == 0) {
            return 1;
        }
    }
    return 0;
}

/* Exercise 4 */
void print_ascii_table(void) {
    unsigned int i;
    for (i = 0; i < 256; i++) {
        printf("%d: %c\n", i, i);
    }
    printf("\n");
}

/* Exercise 5 */
void print_bits(char c) {
    /* Char = 8 bytes -> go from 7 to 0 */
    int i;
    for (i = 7; i >= 0; i--) {
        /* use bitmasking to extract integer at given position */
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}

/* Exercise 6 */
void print_float_bits(float f) {
    /* Float -> 32 byte - 16 bytes decimal */
    int i = 31;
    int float_to_int = *(int *) &f;
    while (i >= 0) {
        /* use bitmasking to extract integer at given position */
        printf("%d", (float_to_int >> i) & 1);
        i--;
    }
    printf("\n");
}

/* Main */
int main(int argc, char *argv[]) {
    printf("Factorial of 5 is %d\n", fact_loop(5));
    printf("Factorial of 5 is %d\n", fact_rec(5));
    printf("Fibonacci of 5 is %d\n", fibo(5));
    printf("Is 5 prime? %d\n", is_prime(5));
    printf("Is 6 prime? %d\n", is_prime(6));
    print_ascii_table();
    print_bits('A');
    print_float_bits(3.14);
}
