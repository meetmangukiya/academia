#include "sort.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
#define MAX_ARRAY_SIZE 100

void radix_sort(int* array, int size)
{
    int size_array[MAX_ARRAY_SIZE] = {0};
    int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    int pass = 0;
    int sorted = 0;

    while(!sorted)
    {
        // Copy the elements to matrix
        for(int i = 0; i < size; i++)
        {
            int row = (array[i] / (int)(pow(10, pass))) % 10;
            int col = size_array[row]++;
            matrix[row][col] = array[i];
        }

        // Copy the elements from matrix to array
        for(int j = 0, l = 0; j < size; j++)
        {
            for(int k = 0; k < size_array[j]; k++, l++)
            {
                array[l] = matrix[j][k];
            }
        }

        // Check if the elements are sorted
        sorted = 1;
        for(int i = 1; i < size; i++)
        {
            if (size_array[i] != 0)
            {
                sorted = 0;
                break;
            }
        }

        // Reset the size_array to 0;
        for(int i = 0; i < size; i++)
            size_array[i] = 0;

        pass++;
    }
}
