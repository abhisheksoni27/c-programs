#include <stdio.h>
#include <math.h>
int main()
{
    int n, a[100], i, p, decimal = 0;

    printf("Enter binary number\n");

    scanf("%d", &n);
    i = 0;
    while (n > 0)
    {
        a[i] = n % 10;
        n = n / 10;
        i++;
        printf("\n%d\n", i);
    }

    for (p = i - 1; p >= 0; p--)
    {
        decimal += a[p] * pow(2, p);
    }

    printf("%d\n", decimal);
    return 0;
}
