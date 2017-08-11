#include <stdio.h>
#include <math.h>

void main()
{
    float func(float);

    float h, mul_3, not_mul_3 , ans;

    mul3 = 0.0;

    not_mul_3 = 0.0;

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
    
        if (i % 3 == 0)
        {
            mul3 += 2 * y[i];
        }
        else
        {
            not_mul_3 += 3 * y[i];
        }
    }

    y[n] = func(x[n]);

    ans = ((3*h) / 8.0) * (y[0] + y[n] + mul3 + not_mul_3);

    printf("\nThe answer is: %f\n", ans);
}

float func(float x)
{
    float g;
    g = sin(x) - log(x) + exp(x);
    return g;
}