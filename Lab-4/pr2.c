/*Write a program to represent the polynomial equation of single variable using single linked
list and perform the addition of two polynomial equations.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int COEFF;
    int EXPO;
    struct Node *NEXT;
};

struct Node* create (struct Node *Head, int k);
struct Node* add_poly (struct Node *Head1, struct Node *Head2);
void print (struct Node *temp);

int main ()
{
    int k1, k2;
    struct Node *Head1, *Head2, *Head3, *temp, *New;
    printf ("Enter the no:of terms in polynomial 1:- ");
    scanf ("%d", &k1);
    Head1 = create (Head1, k1);
    printf ("Polynomial 1 :- ");
    print (Head1);
    printf ("Enter the no:of terms in polynomial 2:- ");
    scanf ("%d", &k2);
    Head2 = create (Head2, k2);
    printf ("Polynomial 2 :- ");
    print (Head2);
    printf ("Adding both the polynomials :- ");
    Head3 = add_poly(Head1, Head2);
    print (Head3);
    return 0;
}

struct Node* create (struct Node *Head, int k)
{
    struct Node *New, *temp;
    Head = NULL;
    for (int i = 0; i < k; i ++)
    {
        New = (struct Node *)malloc(sizeof(struct Node));
        if (New == NULL)
        {
            printf ("Memory Allocation failed\n");
            exit(0);
        }

        printf ("Enter the coefficient :- ");
        scanf ("%d", &New->COEFF);
        printf ("Enter the ecponent :- ");
        scanf ("%d", &New->EXPO);
        New->NEXT = NULL;
        //temp = New;
        if (Head == NULL)
        {
            Head = New;
            temp = New;
        }
        else
        {
            temp->NEXT = New;
            temp = temp->NEXT;
        }
    }
    return Head;
}

struct Node* add_poly (struct Node *Head1, struct Node *Head2)
{
    struct Node *Head3 = NULL, *temp1, *temp2, *temp3, *New;
    temp1 = Head1;
    temp2 = Head2;
    while ((temp1 != NULL) && (temp2 != NULL))
    {
        New = (struct Node *)malloc(sizeof(struct Node));
        if ((temp1->EXPO) > (temp2->EXPO))
        {
            New->COEFF = temp1->COEFF;
            New->EXPO = temp1->EXPO;
            New->NEXT = NULL;
            temp1 = temp1->NEXT;
        }
        else if ((temp2->EXPO) > (temp1->EXPO))
        {
            New->COEFF = temp2->COEFF;
            New->EXPO = temp2->EXPO;
            New->NEXT = NULL;
            temp2 = temp2->NEXT;
        }
        else
        {
            New->COEFF = temp1->COEFF + temp2->COEFF;
            New->EXPO = temp1->EXPO;
            New->NEXT = NULL;
            temp1 = temp1->NEXT;
            temp2 = temp2->NEXT;
        }
        if (Head3 == NULL)
        {
            Head3 = New;
            temp3 = New;
        }
        else
        {
            temp3->NEXT = New;
            temp3 = temp3->NEXT;
        }   
    }
    while (temp1 != NULL)
    {
        New->COEFF = temp1->COEFF;
        New->EXPO = temp1->EXPO;
        New->NEXT = NULL;
        temp1 = temp1->NEXT;
        temp3->NEXT = New;
        temp3 = New;
    }
    while (temp2 != NULL)
    {
        New->COEFF = temp2->COEFF;
        New->EXPO = temp2->EXPO;
        New->NEXT = NULL;
        temp2 = temp2->NEXT;
        temp3->NEXT = New;
        temp3 = New;
    }
    return Head3;
}

void print (struct Node *temp)
{
    while (temp != NULL)
    {
        printf ("%dx^%d", temp->COEFF, temp->EXPO);
        if (temp->NEXT != NULL)
        {
            printf (" + ");
        }
        temp = temp->NEXT;
    }
    printf ("\n");
}