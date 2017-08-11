#include <stdio.h>
#include <math.h>

void main()
{
    float func(float);

    float h, k1, k2, k3, k4, ans;

    k1 = 0;
    k2 = 0;
    k3 = 0;
    k4 = 0;

    int i, n;

    float x[20], y[20];

    printf("\nEnter number of parts: ");

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
        
        if (i % 6 == 0)
        {
            k1 += 2 * y[i];
        }
        else if (i % 3 == 0)
        {
            k2 += 6 * y[i];
        }
        else if (i % 2 == 0)
        {
            k3 += y[i];
        }
        else
        {
            k4 += 5 * y[i];
        }
    }

    y[n] = func(x[n]);

    ans = ((3 * h) / 10.0) * (y[0] + y[n] + k1 + k2 + k3 + k4);

    printf("\nThen answer is: %f\n", ans);
}

float func(float x)
{
    float g;
    g = sin(x) - log(x) + exp(x);
    return g;
}