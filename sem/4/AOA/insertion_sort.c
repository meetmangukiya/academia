#include "sort.h"

void insertion_sort(int* array, int size) {
    int i;
    for(i = 0; i < size - 1; i++) {
        int target = array[i+1];
        int insertion_pos = 0;

        while(array[insertion_pos] < target)
            insertion_pos++;

        int j = i;
        while(j >= insertion_pos) {
            array[j + 1] = array[j];
            j--;
        }

        array[insertion_pos] = target;
    }
}
