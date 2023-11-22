double func(double t, double y);

double preditorCorretorMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1][2])
{
    rungeKuttaMethod(3, timeStart, step, solution);

    double valueEstimatedOfFunction, valueFixedOfFunction, currentTime;

    unsigned int iterator = 4;

    do
    {
        currentTime = timeStart + iterator * step;

        valueEstimatedOfFunction = solution[iterator - 1][1] +
                                   (step * (55 * func(solution[iterator - 1][0], solution[iterator - 1][1]) -
                                            59 * func(solution[iterator - 2][0], solution[iterator - 2][1]) +
                                            37 * func(solution[iterator - 3][0], solution[iterator - 3][1]) -
                                            9 * func(solution[iterator - 4][0], solution[iterator - 4][1]))) /
                                       24;

        valueFixedOfFunction = solution[iterator - 1][1] +
                               (step * (9 * func(currentTime, valueEstimatedOfFunction) +
                                        19 * func(solution[iterator - 1][0], solution[iterator - 1][1]) -
                                        5 * func(solution[iterator - 2][0], solution[iterator - 2][1]) +
                                        func(solution[iterator - 3][0], solution[iterator - 3][1]))) /
                                   24;

        solution[iterator][0] = currentTime;

        solution[iterator][1] = valueFixedOfFunction;

        // printf("t = %f, y = %f\n", solution[iterator - 1][0], solution[iterator - 1][1]);

        iterator++;

    } while (iterator <= numberOfSteps);
}
