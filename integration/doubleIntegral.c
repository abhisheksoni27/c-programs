#include <stdio.h>
#include <math.h>

float func(float x, float y)
{
    return 1;
}

void main()
{
    int i, j;

    float h, k, x, y, a, b, c, d, xy[200][200], ax[200], ans;

    printf("Integral a to b, integral c to d (function) dx/dy");

    printf("\n Enter the following values \n");

    printf("\n a = ");
    scanf("%f", &a);
    
    printf("\n b = ");
    scanf("%f", &b);
    
    printf("\n c =  ");
    scanf("%f", &c);
    
    printf("\n d =  ");
    scanf("%f", &d);
    
    printf("\n h = ");
    scanf("%f", &h);
    
    printf("\n k = ");
    scanf("%f", &k);

    x = ((b - a) / h);

    y = ((d - c) / k);

    printf("\n x=%f , y=%f \n", x, y);

    for (i = 0; i <= x; i++)
    {
        for (j = 0; j <= y; j++)
        {
            xy[i][j] = func(a + i * h, c + j * k);  
        }
    }

    for (i = 0; i <= x; i++)
    {
        ax[i] = 0;

        for (j = 0; j <= y; j++)
        {
            if (j == 0 || j == y)
                ax[i] += xy[i][j];
            else if (j % 2 == 0)
                ax[i] += 2 * xy[i][j];
            else
                ax[i] += 4 * xy[i][j];
        }

        ax[i] = (h / 3) * ax[i];

    }

    ans = 0;

    for (i = 0; i <= x; i++)
    {

        if (i == 0 || i == x)
            ans += ax[i];
        else if (i % 2 == 1)
            ans += 4 * ax[i];
        else
            ans += 2 * ax[i];
    }

    ans = (k / 3) * ans;

    printf("\nValue of integral is %f", ans);
}