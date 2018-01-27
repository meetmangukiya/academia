#include <stdio.h>
#include "utils.h"

void bubble_sort(int*, int);

int main() {
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;

    printf("Before sorting: ");
    print_int_array(array, size);

    bubble_sort(array, size);

    printf("\nAfter sorting: ");
    print_int_array(array, size);

    return 0;
}

void bubble_sort(int* array, int len) {
    int i, j;
    for(i = len - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}
