#include "sort.h"

void insertion_sort_with_gap(int* array, int size, int gap) {
    int i;
    for(i = 0; i < size - 1; i += gap) {
        int target = array[i+gap];
        int insertion_pos = 0;

        while(array[insertion_pos] < target)
            insertion_pos += gap;

        int j = i;
        while(j >= insertion_pos) {
            array[j + gap] = array[j];
            j -= gap;
        }

        array[insertion_pos] = target;
    }
}

void insertion_sort(int* array, int size) {
    insertion_sort_with_gap(array, size, 1);
}
