#include "sort.h"

void shell_sort(int* array, int len) {
    int gap = len / 2;
    int i;
    while (gap != 0) {
        for(int i = 0; i < gap; i++) {
            insertion_sort_with_gap(array + i, len, gap);
        }
        gap = gap / 2;
    }
}
