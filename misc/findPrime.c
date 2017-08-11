#include <stdio.h>
#include <math.h>

int main()
{
    int i, j;

    int primeArray[100];

    primeArray[0] = 2;

    int p = 1;
    
    int flag;

    for (i = 3; i < 100; i++)
    {
        flag = 1;
        for (j = 2; j < i ; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            primeArray[p] = i;
            p++;
        }
    }

    for (i = 0; i < p; i++)
    {
        printf("The prime number %d is: %d\n", i + 1, primeArray[i]);
    }
}
