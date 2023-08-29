//Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>
int main ()
{
    int a, b;
    printf ("Enter two numbers : ");
    scanf ("%d, %d", &a, &b);
    printf ("\n");
    MaxNum (&a, &b);
}

void MaxNum (int *x, int *y)
{
    if (*x > *y)
    {
        printf ("%d is greater than %d", *x, *y);
    }
    else if (*y > *x)
    {
        printf ("%d is less than %d", *x, *y);
    }
    else
    {
        printf ("Both numbers are same.");
    }
}
    