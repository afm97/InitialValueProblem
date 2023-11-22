#include <stdio.h>

void printMatrix(int rows, double matrix[rows][2])
{
    for (int i = 0; i < rows; i++)
    {
        printf("%f, %f \n", matrix[i][0], matrix[i][1]);
    }
}