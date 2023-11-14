#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE][MAX_SIZE];

int main ()
{
    int m, n, ch, i, j, c = 0;
    printf ("Enter the number of rows and colums: \n");
    scanf ("%d%d", &m, &n);
    printf ("Enter the array elements :\n");
    for (i = 0; i < m; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            scanf ("%d", &arr[i][j]);
        }
    }

    printf ("Displaying the matrix :- \n");
    for (i = 0; i < m; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            printf ("%d ", arr[i][j]);
        }
        printf ("\n");
    }
    printf ("No:of Non-Zero Elements are :- ");
    for (i = 0; i < (m); i ++)
    {
        for (j = 0; j < (n); j ++)
        {
            if (arr[i][j] != 0)
            {
                c ++;
            } 
        }
    }
    printf ("%d\n", c);

    printf ("The Upper Triangular Matrix : \n");
    for (i = 0; i < (m); i ++)
    {
        for (j = 0; j < (n); j ++)
        {
            if (j > i)
            {
                printf ("%d ", arr[i][j]);
            }
            if (i > j)
            {
                printf("  ");  
            }
        }
        printf ("\n");
    }
    
    printf ("Elements of just above and below the main diagonal are :- \n");
    for (i = 0; i < (m); i ++)
    {
        for (j = 0; j < (n); j ++)
        {
            if (i > j)
            {
                printf(" ");  
            }
            if (i != j)
            {
                printf ("%d", arr[i][j]);
            }
        }
        printf ("\n");
    }
}
