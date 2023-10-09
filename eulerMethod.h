double func(double y, double t);

double eulerMethod(double *solution, double timeStart, double step, unsigned int maxOfSteps)
{
    unsigned int iterator = 1;

    do
    {

        solution[iterator] = solution[iterator - 1] + step * func(solution[iterator - 1], timeStart);

        timeStart = iterator * step;

        iterator++;

    } while (iterator <= maxOfSteps);
}