double func(double y, double t);

double eulerMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1])
{
    double currentTime;
    unsigned int iterator = 0;

    do
    {
        currentTime = timeStart + iterator * step;

        solution[iterator + 1] = solution[iterator] + step * func(currentTime, solution[iterator]);

        iterator++;

    } while (iterator <= numberOfSteps);
}