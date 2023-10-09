#include <stdio.h>

void printArray(int rows, double *matrix)
{
    for (int i = 0; i < rows; i++)
    {
        printf("%f  \n", matrix[i]);
    }
}