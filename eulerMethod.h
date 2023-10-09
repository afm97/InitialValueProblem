double func(double y, double t);

double eulerMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1])
{
    unsigned int iterator = 0;

    do
    {
        timeStart = iterator * step;

        solution[iterator + 1] = solution[iterator] + step * func(solution[iterator], timeStart);

        iterator++;

    } while (iterator <= numberOfSteps);
}