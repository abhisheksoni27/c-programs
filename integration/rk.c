#include <stdio.h>
#include <math.h>
float f(float x, float y);

int main()
{
    float x0, y0, k1, k2, k3, k4, k, y, x, h, xn;
    
    printf("Enter x0, y0, xn, h:");
    scanf("%f %f %f %f", &x0, &y0, &xn, &h);
    
    x = x0;
    y = y0;
    
    printf("\n \n X \t \t Y\n");
    while (x < xn)
    {

        k1 = f(x, y);

        k2 = f((x + h / 2.0), (y + k1 / 2.0));

        k3 = f((x + h / 2.0), (y + k2 / 2.0));

        k4 = f((x + h), (y + k3));

        k = ((k1 + 2 * k2 + 2 * k3 + k4) / 6);

        y += k*h;

        x += h;

        printf("%f \t %f \n", x, y);
    }
}

float f(float x, float y)
{
    float m;
    m = 2 * x;
    return m;
}