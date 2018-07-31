#include "sort.h"

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
