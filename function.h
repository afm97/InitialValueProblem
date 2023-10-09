#include <stdio.h>
#include <stdlib.h>

double func(double y, double time)
{
    printf("y = %f, t = %f\n", y, time);
    return (y - pow(time, 2) + 1);
}