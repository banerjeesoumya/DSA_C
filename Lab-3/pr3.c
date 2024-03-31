#include <stdio.h>
#define MAX_SIZE 100

int P[MAX_SIZE], Q[MAX_SIZE], R[MAX_SIZE];

void form_Polynomial(int X[]);
void print_Polynomial(int *e, int X[]);
void Sum(int *e, int P[], int Q[]);

int main()
{
    int e;
    printf("Enter the maximum degree: ");
    scanf("%d", &e);

    // Initialize the arrays P and Q
    for (int i = 0; i <= e; i++)
    {
        P[i] = 0;
        Q[i] = 0;
    }

    form_Polynomial(P);
    printf("Polynomial 1: ");
    print_Polynomial(&e, P);

    form_Polynomial(Q);
    printf("Polynomial 2: ");
    print_Polynomial(&e, Q);

    Sum(&e, P, Q);
    printf("Resultant Polynomial: ");
    print_Polynomial(&e, R);
}

void form_Polynomial(int X[])
{
    int ch, expo, coeff;

    do
    {
        printf("Enter the exponent part: ");
        scanf("%d", &expo);
        printf("Enter the coefficient part: ");
        scanf("%d", &coeff);

        // Storing the coefficient in the array at the specified exponent
        X[expo] = coeff;

        printf("Do you want to add another term? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch != 'N');
}

void print_Polynomial(int *e, int X[])
{
    for (int i = *e; i >= 0; i--)
    {
        if (X[i] != 0)
        {
            printf("%dx^%d", X[i], i);
            if (i > 0)
            {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

void Sum(int *e, int P[], int Q[])
{
    for (int i = 0; i <= *e; i++)
    {
        R[i] = P[i] + Q[i];
    }
}
