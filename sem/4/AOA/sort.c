#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "utils.h"

int main() {
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;

    char* help = ("\
1: Bubble sort\n\
2: Insertion sort\n\
3: Shell sort\n\
4: Quick sort\n\
5: Radix sort\n\
");

    printf("%s", help);

    int choice;
    printf("\nChoice: ");
    scanf("%d", &choice);

    printf("\nBefore sorting: ");
    print_int_array(array, size);

    switch(choice) {
        case 1:
            bubble_sort(array, size);
            break;
        case 2:
            insertion_sort(array, size);
            break;
        case 3:
            shell_sort(array, size);
            break;
        case 4:
            quick_sort(array, size);
            break;
        case 5:
            radix_sort(array, size);
            break;
        default:
            printf("Wrong choice");
            exit(-1);
            break;
    }

    printf("\nAfter sorting: ");
    print_int_array(array, size);
}
