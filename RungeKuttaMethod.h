double func(double t, double y);

double rungeKuttaMethod(unsigned int numberOfSteps, double timeStart, double step, double solution[numberOfSteps + 1][2])
{
    double K_1, K_2, K_3, K_4, t0, y0, currentTime;

    unsigned int iterator = 1;

    do
    {
        currentTime = timeStart + iterator * step;

        t0 = solution[iterator - 1][0];
        y0 = solution[iterator - 1][1];

        K_1 = step * func(t0, y0);
        K_2 = step * func(t0 + step / 2, y0 + K_1 / 2);
        K_3 = step * func(t0 + step / 2, y0 + K_2 / 2);
        K_4 = step * func(t0 + step, y0 + K_3);

        solution[iterator][0] = currentTime;
        solution[iterator][1] = y0 + (K_1 + 2 * K_2 + 2 * K_3 + K_4) / 6;

        iterator++;

    } while (iterator <= numberOfSteps);
}
