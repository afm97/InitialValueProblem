double func(double t, double y);

double rungeKuttaHighOrderMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1])
{
    double K_1, K_2, K_3, K_4, K_5, K_6, currentTime;
    unsigned int iterator = 0;

    do
    {
        currentTime = timeStart + iterator * step;

        K_1 = func(currentTime, solution[iterator]);
        K_2 = func(currentTime + step / 4, solution[iterator] + K_1 * step / 4);
        K_3 = func(currentTime + step / 4, solution[iterator] + (K_2 + K_1) * step / 8);
        K_4 = func(currentTime + step / 2, solution[iterator] + (K_3 - K_2 / 2) * step);
        K_5 = func(currentTime + 3 * step / 4, solution[iterator] + (9 * K_4 + 3 * K_1) * step / 16);
        K_6 = func(currentTime + step / 2, solution[iterator] + (8 * K_5 - 12 * K_4 + 12 * K_3 + 2 * K_2 - 3 * K_1) * step / 7);

        solution[iterator + 1] = solution[iterator] + (7 * K_1 + 32 * K_3 + 12 * K_4 + 32 * K_5 + 7 * K_6) * step / 90;

        iterator++;

    } while (iterator <= numberOfSteps);
}