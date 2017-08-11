// This is the correct one. Tho that one worked too. :thinking:

#include <stdio.h>

void main()
{

    float ax[20], ay[20];

    float x = 0, y = 0, xy = 0, x_x, m;

    int i, n;

    float a, c;

    printf("Enter no. of data points: ");

    scanf("%d", &n);

    printf("\nEnter data points (x,y) in that order: \n");

    printf("\nX \t \t Y\n");

    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &ax[i], &ay[i]);
    }

    for (i = 0; i < n; i++)
    {
        x += ax[i];

        y += ay[i];

        xy += ax[i] * ay[i];

        x_x += ax[i] * ax[i];
    }

    printf("\n%f\n, \n%f\n, \n%f\n, \n%f\n", x, y, xy, x_x);

    m = ((n * xy) - (x * y)) / ((n * x_x) - (x * x));

    c = (y - (m * x)) / n;

    printf("\nm = %f    c = %f\n", m, c);

    printf("\nThe Equation is y = %fx + %f\n\n", m, c);
}