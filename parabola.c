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