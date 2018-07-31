#include "sort.h"

int partition(int* arr, int sizee, int pivot) {
    int lower_elements[sizee];
    int higher_elements[sizee];
    int li, hi;
    li = hi = -1;

    int element = arr[pivot];

    int i;
    for(i = 0; i < sizee; i++) {
        if (i != pivot) {
            if (arr[i] < arr[pivot]) {
                lower_elements[++li] = arr[i];
            }
            else {
                higher_elements[++hi] = arr[i];
            }
        }
        else {
            continue;
        }
    }
    for(i = 0; i <= li; i++) {
        arr[i] = lower_elements[i];
    }
    arr[i] = element;
    int pivot_index = i;
    int j;
    for(j = 0; j <= hi; j++) {
        arr[++i] = higher_elements[j];
    }
    return pivot_index;
}

void quick_sort(int* arr, int sizee) {
    int pivot = 0;
    if (sizee == 1 || sizee == 0 || sizee == -1) {
        return;
    }
    int index = partition(arr, sizee, pivot);
    quick_sort(arr, index);
    quick_sort(arr + index + 1, sizee - index - 1);
}
