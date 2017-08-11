## Gauss Elimination

```C
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
```

## Gauss Jordan

```C
#include <stdio.h>
int main()
{
    int i, j, k, n;

    float A[20][20], c, x[10];

    printf("\nEnter the size of matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n + 1); j++)
        {
            printf(" A[%d][%d]:", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n + 1); j++)
        {
            printf("%f \t", A[i][j]);
        }
        printf("\n");
    }
    
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (i != j)
            {
                c = A[i][j] / A[j][j];
                for (k = 0; k < n + 1; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                    printf("A[%d][%d]: %f \t", i, k, A[i][k]);
                }
                printf("\n");
            }
        }
    }
    
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++)
    {
        x[i] = A[i][n] / A[i][i];
        printf("\nA[%d][%d]: %f\n", i, n+1,A[i][n]);
        printf("\n x%d = %f \n", i, x[i]);
    }
    return (0);
}
```


## Parabola Fit

```C
#include <stdio.h>

float arr[3][4], x, y, xx, a, b, c;

int n;

void initialize()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void readdata()
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Pair num %d\n", i + 1);
        scanf("%f %f", &x, &y);

        xx = x * x;

        arr[0][1] += x;

        arr[0][2] += xx;

        arr[1][2] += x * xx;

        arr[2][2] += xx * xx;

        arr[0][3] += y;

        arr[1][3] += x * y;

        arr[2][3] += xx * y;
    }

    arr[1][0] = arr[0][1];

    arr[1][1] = arr[0][2];

    arr[2][0] = arr[1][1];

    arr[2][1] = arr[1][2];
}

void displayaugmentedmatrix()
{
    int i, j;
    printf("The augmented matrix is \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%9.4f", arr[i][j]);
        }
        printf("\n");
    }
}

void applygaussjordon()
{
    int i, j, k;
    float t;
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (i != j)
            {
                t = arr[i][j] / arr[j][j];
                for (k = 0; k < 4; k++)
                {
                    arr[i][k] -= arr[j][k] * t;
                }
            }
        }
    }

    a = arr[0][3] / arr[0][0];
    b = arr[1][3] / arr[1][1];
    c = arr[2][3] / arr[2][2];
}

void displaybestfit()
{
    printf("y=%f", a);

    if (b >= 0)
        printf("+");
    printf("%fx", b);

    if (c > 0)
        printf("+");
    printf("%fx^2", c);
}

void main()
{
    printf("Enter the number of pairs of observed values\n");
    scanf("%d", &n);
    
    initialize(); // Set values to zero
    arr[0][0] = n;
    
    readdata(); // Read pairs and set values
     
    displayaugmentedmatrix(); // Simple matrix print function
    
    applygaussjordon(); // Apply gauss jordan
    
    printf("The best fit curve is\n");
    displaybestfit();
}
```