/** 
 * 50.051 Week 2:
 * 
 * Exercise 1: Printing Array Values
 * Exercise 2: Create and fill an Array
 * Exercise 3: Pascal's Triangle
 * Exercise 4: Convert a char array to upper case
 * Exercise 5: Checking Endianness
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Exercise 1*/
void print_array(int arr[], int size) {
    /* work without global variable declaration */
    int i;
    for (i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

/* Exercise 2 */
void create_dynamic_array (void) {
    /* prompt user for size */
    /* create dynamic array using this */
    /* print using print_array */
    /* use malloc */
    /* free memory */
    int * arr;
    int size;
    int i;
    printf("Input size of array: ");
    scanf("%d", &size);
    printf("\n");
    arr = (int * ) malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        printf("Input element at arr[%d]: ", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    print_array(arr, size);
    free(arr);
}

/* Exercise 3 */
void create_pascal_triangle(int level) {
    /* print pascal triangle */
    /* use malloc */
    int i;
    int j;
    int ** pascal_arr;
    pascal_arr = (int **) malloc(level * sizeof(int *));
    for (i = 0; i < level; i++) {
        pascal_arr[i] = (int *) malloc((i + 1) * sizeof(int));
        pascal_arr[i][0] = 1;
        pascal_arr[i][i] = 1;
        for (j = 1; j < i; j++) {
            pascal_arr[i][j] = pascal_arr[i - 1][j - 1] + pascal_arr[i - 1][j];
        }
    }
    /* printing triangle */
    for (i = 0; i < level; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", pascal_arr[i][j]);
        }
        printf("\n");
    }
    /* freeing individual rows of triangles */
    for (i = 0; i < level; i++) {
        free(pascal_arr[i]);
    }
    /* free full remaining array */
    free(pascal_arr);
}

/* Exercise 4 */
char * to_uppercase(const char *str) {
    /* create copy of str */
    /* convert to upper case */
    /* return */
    char * copy;
    int i;
    copy = (char *) malloc((strlen(str) + 1) * sizeof(char));
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 97) {
            copy[i] = str[i] - 32;
        } else {
            copy[i] = str[i];
        }
    }
    return copy;
}

/* Exercise 5 */
void check_endianness(void) {

}

int main(int argc, char ** argv) {
    int arr[] = {1, 2, 3, 4, 5};
    int pasc_size;
    char * upper;
    print_array(arr, sizeof(arr)/sizeof(int));
    create_dynamic_array();
    printf("Input size of pascal triangle: ");
    scanf("%d", &pasc_size);
    create_pascal_triangle(pasc_size);
    upper = to_uppercase("Hello World");
    printf("Modified: %s\n", upper);
    return 0;
}
