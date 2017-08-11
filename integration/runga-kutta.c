#include <stdio.h>

float func(float x, float y)
{
    return y - ( (2 * x) / y );
}

void main()
{

    float x0 = 0.2, y0 = 1, h = 0.1;

    float k1, k2, k3, k4, ans;

    k1 = h * func(x0, y0);
    k2 = h * func(x0 + h / 2, y0 + k1 / 2);
    k3 = h * func(x0 + h / 2, y0 + k2 / 2);
    k4 = h * func(x0 + h / 2, y0 + k3 / 2);

    ans = y0 + ((1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));

    printf("%f", ans);

}
