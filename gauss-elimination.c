#include <stdio.h>
#include <math.h>

void main()
{
    float temp, s, matrix[3][4], x[3];

    int i, j, k;

    int n = 3;

    printf("\nEnter the elements of the augmented matrix (row wise) : \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("\n Matrix [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Printing Matrix

    printf("\n Matrix: \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%f \t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\n");

    /*now calculating the upper triangular matrix */
    for (j = 0; j < n - 1; j++)
    {
        for (i = j + 1; i < n; i++)
        {
            temp = matrix[i][j] / matrix[j][j];
            for (k = 0; k < n + 1; k++)
            {
                matrix[i][k] -= matrix[j][k] * temp;
            }
        }
    }

    //now performing back substitution

    for (i = n - 1; i >= 0; i--)
    {
        s = 0;
        for (j = i + 1; j < n; j++)
        {
            printf("%f \t", x[j]);
            s += matrix[i][j] * x[j];
        }
        x[i] = (matrix[i][n] - s) / matrix[i][i];
    }

    //now printing the result
    printf("\n Solution is : \n");
    for (i = 0; i < n; i++)
        printf("\n x[%d] = %7.4f ", i + 1, x[i]);
}