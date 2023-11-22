double func(double t, double y);

double rungeKuttaMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1][2])
{
    double K_1, K_2, K_3, K_4, currentTime, y0;

    unsigned int iterator = 1;

    do
    {
        currentTime = timeStart + iterator * step;

        y0 = solution[iterator][1];

        K_1 = step * func(currentTime, y0);
        K_2 = step * func(currentTime + step / 2, y0 + K_1 / 2);
        K_3 = step * func(currentTime + step / 2, y0 + K_2 / 2);
        K_4 = step * func(currentTime + step, y0 + K_3);

        printf("tempo atual = %f\n", currentTime);

        solution[iterator][0] = currentTime;
        solution[iterator][1] = y0 + (K_1 + 2 * K_2 + 2 * K_3 + K_4) / 6;

        iterator++;

    } while (iterator <= numberOfSteps);
}
