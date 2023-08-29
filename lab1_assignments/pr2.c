//Write a program to create an array of n elements using dynamic memory allocation.
//Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int n, *a, s = 0;    
    printf ("Enter the number of elements of the array : ");
    scanf ("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf ("Unsuccesfull Memory Allocation \n");
        exit(0);
    }
    printf ("Enter the array elements\n");
    for (int i = 0; i < n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        int p = prime(a[i]);
        s = s + p;
    }
    printf ("The sum of the prime elements are :- %d", s);
}

int prime (int n)
{
    int c = 0;
    for (int i = 1; i <= n; i ++)
    {
        if ((n % i) == 0)
        {
            c ++;
        }
    }
    if (c == 2)
        return n;
    else
        return 0;
}