#ifndef AOA_UTILS

#define AOA_UTILS

#include <stdio.h>

void print_int_array(int* array, int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
}

#endif
