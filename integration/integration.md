# Integration

* [Trapezoidal](#trapezoidal)
* [Simpson's 1/3 rule](#simpsons-13-rule)
* [Simpson's 3/8 rule](#simpsons-38-rule)
* [Weddle's rule](#weddles-rule)
* [Boole's](#booles-rule)
* [Runga-Kutta](#runga-kutta)
* [Double Integral](#double-integral)

## Trapezoidal

_n_ &ndash; Number of parts

_h_ = (xn - x0) / n

_x[i]_ = x0 + i * h

_ytimestwo_ = **Summation** ( y[i] * 2 )

    answer = ( h/2.0 ) * ( y[0] + y[n] + ytimestwo );

### Code

```C

#include<stdio.h>
#include<math.h>
#include<conio.h>

float f(float x){
  return log(x);
};

int main(){

  float x0, xn, h, y[20], x[20], ytimestwo, ans;

  int i, n;

  clrscr();

  printf("Enter the value of x0, xn, and n. (Maximum value of n is 21.)\n");

  scanf("%f %f %d", &x0, &xn, &n);

  h = (xn-x0)/n;

  ytimestwo = 0.0;

  for(i=1; i<=n; i++){

    x[i] = x0 + i * h;

    y[i] = f(x[i]);

    printf("x: %8.5f, y: %8.5f\n", x[i], y[i]);

    ytimestwo = ytimestwo + 2*y[i];

  }

  ans = (h/2.0) * (y[0] + y[n] + ytimestwo);

  printf("\nThe value of integration is %f",ans);

  getch();

}
```

[Top](#integration)

## Simpson's 1/3 rule

_n_ &ndash; Number of parts

_h_ = (xn - x0) / n

_x[i]_ = x0 + i * h

_se_ = **Summation** ( 2 * y[i] ) where i is **even**

_so_ = **Summation** ( 4 * y[i] ) where i is **odd**

    answer = ( h / 3.0 ) * ( y[0] + y[n] + se + so );

### Code

```C
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

    printf("\nThe answer is: %f\n", ans);
}

float func(float x)
{
    float g;
    g = sin(x) - log(x) + exp(x);
    return g;
}
```

[Top](#integration)

## Simpson's 3/8 rule

_n_ &ndash; Number of parts

_h_ = (xn - x0) / n

_x[i]_ = x0 + i * h

_mul_3_ = **Summation** ( 2 * y[i] ) where i is a multiple of 3

_not_mul_3_ = **Summation** ( 3 * y[i] ) where i is not a multiple of 3

    answer =  ( ( 3 * h ) / 8.0 ) * ( y[0] + y[n] + mul3 + not_mul_3 );

### Code

```C
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
```

[Top](#integration)

## Weddle's rule

_n_ &ndash; Number of parts

_h_ = (xn - x0) / n

_x[i]_ = x0 + i * h

_k1_ = **Summation** ( 2 * y[i] ) where i is a multiple of 6

_k2_ = **Summation** ( 6 * y[i] )where i is a multiple of 3

_k3_ = **Summation** ( y[i] ) where i is a multiple of 2

_k4_ = **Summation** ( 5 * y[i] ) all the rest of the terms

    answer = ( ( 3 * h ) / 10.0 ) * (y[0] + y[n] + k1 + k2 + k3 + k4);

### Code

```C
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
```

[Top](#integration)

## Boole's rule

_n_ &ndash; Number of parts

_h_ = (xn - x0) / n

_x[i]_ = x0 + i * h

_k1_ = **Summation** ( 14 * y[i] ) where i is a multiple of 4

_k2_ = **Summation** ( 12 * y[i] )where i is a multiple of 2

_k3_ = **Summation** ( y[i] ) where i is a multiple of 2

    answer = ( (2 * h) / (45.0) ) * ( y[0] + y[n] + k1 + k2 + k3 );

### Code

```C
#include <stdio.h>
#include <math.h>

void main()
{
    float func(float);

    float h, k1, k2, k3, ans;

    k1 = 0;
    k2 = 0;
    k3 = 0;

    int i, n;

    float x[20], y[20];

    printf("\nEnter number of parts: ");

    scanf("%d", &n);

    printf("\nEnter the upper and lower limts.\n");

    scanf("%f %f", &x[0], &x[n]);

    y[0] = 7 * func(x[0]);

    h = (x[n] - x[0]) / n;

    for (i = 1; i < n; i++)
    {
        x[i] = x[0] + i * h;

        y[i] = func(x[i]);

        printf("\nx: %8.5f, y: %8.5f\n", x[i], y[i]);

        if (i % 4 == 0)
        {
            k1 += 14 * y[i];
        }
        else if (i % 2 == 0)
        {
            k2 += 12 * y[i];
        }
        else
        {
            k3 += 32*y[i];
        }
    }

    y[n] = 7*func(x[n]);

    ans = ((2 * h) / (45.0)) * (y[0] + y[n] + k1 + k2 + k3 + k4);

    printf("\nThen answer is: %f\n", ans);
}

float func(float x)
{
    float g;
    g = sin(x) - log(x) + exp(x);
    return g;
}
```

[Top](#integration)

## Runga-Kutta (Order 4)

_x0_ &ndash; initial value of x

_y0_ &ndash; initial value of y at **x0**

_h_ &ndash; width of the strip

Initialize `x` and `y`
x = x0
y = y0

_**[Begin Loop]**_ (Run Until we reach xn)

_k1_ = h * function( x, y )

_k2_ = h * function( x + h/2 , y + k1 / 2.0)

_k3_ = h * function( x + h/2 , y + k2 / 2.0)

_k4_ = h * function( x + h/2 , y + k3 * h)

    answer = y0 + ((1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));

Increment x and y

x = x + h;

y = y + k * h;

_**[Loop]**_

### Code

```C
#include <stdio.h>

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

        k4 = f((x + h), (y + k3 * h));

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

```
[Top](#integration)

## Double Integral

```C
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
```
