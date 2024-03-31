#include <stdio.h>
#define MAX_SIZE 100

void formSparse(int *r, int *c, int *el, int X[][3]);
void displaySparse (int *el, int X[][3]);
void perform_Addition (int X[][3], int Y[][3], int *el1, int *el2 );

int A[MAX_SIZE][3], B[MAX_SIZE][3], T[MAX_SIZE][3];

int main() 
{
    int r, c, el1, el2;
    printf("Enter the number of rows for both the first and second matrix: ");
    scanf("%d", &r);
    printf("Enter the number of columns for both the first and second matrix: ");
    scanf("%d", &c);
    printf("Enter the number of elements for Matrix - 1: \n");
    scanf("%d", &el1);
    formSparse(&r, &c, &el1, A);
    printf ("Sparse Matrix-1 in 3 tuple format :- \n");
    displaySparse(&el1, A);
    printf("Enter the number of elements for Matrix - 2: \n");
    scanf("%d", &el2);
    formSparse(&r, &c, &el2, B);
    printf ("Sparse Matrix-2 in 3 tuple format :- \n");
    displaySparse(&el2, B);
    perform_Addition (A, B, &el1, &el2);
    return 0;
}

void formSparse(int *r, int *c, int *el, int X[][3]) 
{
    X[0][0] = (*r);
    X[0][1] = (*c);
    X[0][2] = (*el);

    for (int i = 1; i <= (*el); i++) 
    {
        printf("Enter the row no. column no. (having the non-zero element), and the non-zero element: ");
        scanf("%d%d%d", &X[i][0], &X[i][1], &X[i][2]);
    }
}

void displaySparse (int *el, int X[][3])
{
    for (int i = 0; i < (*el + 1); i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d  ", X[i][j]);
        }
        printf("\n");
    }
}
void perform_Addition (int X[][3], int Y[][3], int *el1, int *el2 )
{
    int i, j, k, c = 0;
    i=j=k=1;
    T[0][0] = X[0][0];
    T[0][1] = X[0][1];

    while ((i <= (X[0][0])) && (j <= (Y[0][0])))
    {
        if (X[i][0] == Y[j][0])
        {
            if (X[i][1] == Y[j][1])
            {
                T[k][0] = X[i][0];
                T[k][1] = X[i][1];
                T[k][2] = X[i][2] + Y[j][2];
                i++;j++;k++;c++;
            }
            else if (X[i][1] < Y[j][1])
            {
                T[k][0] = X[i][0];
                T[k][1] = X[i][1];
                T[k][2] = X[i][2];
                i++;k++;c++;
            }
            else
            {
                T[k][0] = Y[j][0];
                T[k][1] = Y[j][1];
                T[k][2] = Y[j][2];
                j++;k++;c++;
            }
        }
        else
        {
            if (X[i][0] < Y[j][0])
            {
                T[k][0] = X[i][0];
                T[k][1] = X[i][1];
                T[k][2] = X[i][2];
                i++;k++;c++; 
            }
            else
            {
                T[k][0] = Y[j][0];
                T[k][1] = Y[j][1];
                T[k][2] = Y[j][2];
                j++;k++;c++;
            }
        }
    }
    while (i <= (X[0][0]))
    {
        T[k][0] = X[i][0];
        T[k][1] = X[i][1];
        T[k][2] = X[i][2];
        i++;c++;
    }
    while (j <= (Y[0][0]))
    {
        T[k][0] = Y[j][0];
        T[k][1] = Y[j][1];
        T[k][2] = Y[j][2];
        j++;c++;
    }
    T[0][2] = c;
    
    printf ("Resultant Matrix in 3-tuple format :- \n");
    for (int m = 0; m < (c + 1); m ++)
    {
        for (int n = 0; n < 3; n ++)
        {
            printf ("%d  ", T[m][n]);
        }
        printf ("\n");
    }
}