/*WAP to represent a given sparse matrix in 3-tuple format using 2-D array.*/

#include <stdio.h>
#define MAX_SIZE 100;

int A[100][100];
int T[100][100];
int Non_Zero (int *m, int *n);

int main ()
{
    int i, j, row, col, k;
    printf ("Enter the number of rows and columns of the Sparse Matrix :- \n");
    scanf ("%d %d", &row, &col);
    printf ("Enter the array elements :- \n");
    for (i = 0; i < row; i ++)
    {
        for (j = 0; j < col; j ++)
        {
            scanf ("%d", &A[i][j]);
        }
    }
    int c = Non_Zero(&row, &col);
    //printf ("%d", c);
    T[(c + 1)][3];
    T[0][0] = row;
    T[0][1] = col;
    T[0][2] = c;
    k = 1;
    while (k <= c)
    {
        for (i = 0; i < row; i ++)
        {
            for (j = 0; j < col; j ++)
            {
                if (A[i][j] != 0)
                {
                    T[k][0] = i;
                    T[k][1] = j;
                    T[k][2] = A[i][j];
                    k ++;
                }
            }
        }
    }
    for (i = 0; i < (c + 1); i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            printf ("%d ", T[i][j]);
        }
        printf ("\n");
    }
}

int Non_Zero (int *m, int *n)
{
    int c = 0;
    for (int i = 0; i < (*m); i ++)
    {
        for (int j = 0; j < (*n); j++)
        {
            if (A[i][j] != 0)
                c ++;
        }
    }
    return c;
}
