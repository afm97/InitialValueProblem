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

    double result[problem.NumberOfSteps + 1];
    result[0] = problem.initialCondition;

    eulerMethod(problem.NumberOfSteps + 1, problem.timeStart, step, result);

    printArray(problem.NumberOfSteps + 1, result);
}