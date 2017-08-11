#include <stdio.h>
#include <math.h>

int ReadMatrix(int M[][3], int x, char identifier)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter value for %c [%d][%d]: ", identifier, i + 1, j + 1);
            scanf("%d", &M[i][j]);
        }
    }
    return 0;
}

int main()
{
    int A[3][3], B[3][3], C[3][3], n = 3, i, j, x, y;
    char a = 'A', b = 'B';
    ReadMatrix(A, n, a);
    ReadMatrix(B, n, b);
    return 0;
}
