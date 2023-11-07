double func(double t, double y);

double rungeKuttaMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1])
{
    double K_1, K_2, K_3, K_4, currentTime;
    unsigned int iterator = 0;

    do
    {
        currentTime = timeStart + iterator * step;

        K_1 = step * func(currentTime, solution[iterator]);
        K_2 = step * func(currentTime + step / 2, solution[iterator] + K_1 / 2);
        K_3 = step * func(currentTime + step / 2, solution[iterator] + K_2 / 2);
        K_4 = step * func(currentTime + step, solution[iterator] + K_3);

        solution[iterator + 1] = solution[iterator] + (K_1 + 2 * K_2 + 2 * K_3 + K_4) / 6;

        iterator++;

    } while (iterator <= numberOfSteps);
}
