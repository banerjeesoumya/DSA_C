/*Write a menu driven program to create a stack using linked list and perform the following
operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements */

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int INFO;
    struct Node *NEXT;
};

void Push (int data);
int Pop();
void display ();

struct Node *TOP = NULL;

int main ()
{
    int c;
    do
    {
        printf ("Stack Operations :\n");
        printf ("1. Push\n");
        printf ("2. Pop\n");
        printf ("3. IsEmpty\n");
        printf ("4. Traverse\n");
        printf ("5. Exit\n");
        printf ("Enter your choice : ");
        scanf ("%d", &c);
        switch (c)
        {
        case 1:
            int data;
            printf ("Enter the data to be pushed into the stack : ");
            scanf ("%d", &data);
            Push (data);
            break;
        
        case 2:
            int x = Pop();
            printf ("%d deleted from Stack\n", x);
            break;

        case 3:
            if (TOP == NULL)
            {
                printf ("True, The Stack is empty\n");
            }
            else
            {
                printf ("False, The Stack is not empty\n");
            }
            break;

        case 4:
            display();
            break;

        case 5:
            exit(99);
            break;

        default: 
            printf ("Invalid Choice\n");
            break;
        }
    }while (c <= 4);

    return 0;
}

void Push (int data)
{
    struct Node *New;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->INFO = data;
    New->NEXT = NULL;
    if (TOP == NULL)
    {
        TOP = New;
    }
    else
    {
        New->NEXT = TOP;
        TOP = New;
    }
}

int Pop ()
{
    if (TOP == NULL)
    {
        printf ("Stack Underflow\n");
        return (-999);
    }
    else
    {
        int x;
        x = TOP->INFO;
        TOP = TOP->NEXT;
        return x;
    }
}

void display ()
{
    struct Node *temp;
    temp = TOP;
    while (temp != NULL)
    {
        printf ("%d", temp->INFO);
        if (temp->NEXT != NULL)
        {
            printf (", ");
        }
        temp = temp->NEXT;
    }
    printf("\n");
}