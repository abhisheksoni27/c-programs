#include <stdio.h>
#include <math.h>

void main()
{
    float func(float);

    float h, se, so, ans;

    se = 0.0;
    so = 0.0;

    int i, n;

    float x[20], y[20];

    printf("\nEnter number of parts(Max 20): ");

    scanf("%d", &n);

    printf("\nEnter the upper and lower limts.\n");

    scanf("%f %f", &x[0], &x[n]);

    y[0] = func(x[0]);

    h = (x[n] - x[0]) / n;

    for (i = 1; i < n; i++)
    {
        x[i] = x[0] + i * h;

        y[i] = func(x[i]);

        printf("\nx: %8.5f, y: %8.5f\n", x[i], y[i]);

        if (i % 2 == 0)
        {
            se += 2 * y[i];
        }
        else
        {
            so += 4 * y[i];
        }
    }

    y[n] = func(x[n]);

    ans = (h / 3.0) * (y[0] + y[n] + se + so);

    printf("\nThen answer is: %f\n", ans);
}

float func(float x)
{
    float g;
    g = exp((x * x) * sin(x * 3));

    return g;
}