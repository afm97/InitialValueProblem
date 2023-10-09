#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"
#include "increment.h"
#include "dataFormat.h"
#include "printArray.h"
#include "eulerMethod.h"

int main()
{
    boundaryConditions problem = {.timeStart = 0.0,
                                  .timeEnd = 2.0,
                                  .NumberOfSteps = 4,
                                  .initialCondition = 0.5};

    double step = increment(problem.timeStart, problem.timeEnd, problem.NumberOfSteps);

    double *result = malloc(sizeof(double) * (problem.NumberOfSteps + 1));
    result[0] = problem.initialCondition;

    eulerMethod(result, problem.timeStart, step, problem.NumberOfSteps + 1);

    printArray(problem.NumberOfSteps + 1, result);
    free(result);
    result = NULL;
}