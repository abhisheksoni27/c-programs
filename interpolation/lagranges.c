#include <stdio.h>
#include <math.h>

void main()
{
    int i, j, n;

    float ax[50], ay[50], num, den, x, y;

    x = 0;
    y = 0;

    printf("\nEnter number of Points (Max: 50):");

    scanf("%d", &n);

    printf("\nEnter the data points x and y, in that order.");

    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &ax[i], &ay[i]);
    }

    printf("\nEnter the value of x for which f(x) is to be calculated:");

    scanf("%f", &x);

    for (i = 0; i < n; i++)
    {
        num = den = 1;

        for (j = 0; j < n; j++)

            if (j != i)
            {
                num *= (x - ax[j]);

                den *= (ax[i] - ax[j]);
            }

        y += (num / den) * (ay[i]);
    }

    printf("\nData Point: \n x ----> %f \t y ----> %f \n", x, y);
}