/*Write a menu driven program to create a stack using array and perform the following
operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements*/

#include <stdio.h>
int STACK [100];
int TOP = -1, size;

void Push (int data);
int Pop ();
void display ();

int main ()
{
    int c;
    printf ("Enter the size of the stack :- ");
    scanf ("%d", &size);
    do
    {
        printf ("Stack Operations :\n");
        printf ("1. Push\n");
        printf ("2. Pop\n");
        printf ("3. IsEmpty\n");
        printf ("4. IsFull\n");
        printf ("5. Display\n");
        printf ("Enter your choice: ");
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
            if (TOP == -1)
            {
                printf ("True, Stack is empty\n");
            }
            else
            {
                printf ("False, Stack is not Empty\n");
            }
            break;

        case 4:
            if (TOP == (size - 1))
                printf ("True, Stack is Full\n");
            else
                printf ("False, Stack is not Full\n");
            break;

        case 5:
            display();
            break;


        default:
            printf ("Invalid Choice\n");
            break;
        }
    } while (c <= 5);
    return 0;
}

void Push (int data)
{
    if (TOP == (size - 1))
    {
        printf ("Stack Overflow\n");
        return;       
    }
    else
    {
        TOP ++;
        STACK[TOP] = data;
    }
}

int Pop ()
{
    int x;
    if (TOP == -1)
    {
        printf ("Stack Underflow\n");
        return;
    }
    else
    {
        x = STACK[TOP];
        TOP --;
    }
    return (x);
}

void display ()
{
    for (int i = TOP; i >= 0; i --)
    {
        printf ("%d", STACK[i]);
        if (i != 0)
        {
            printf (" , ");
        }
    }
    printf ("\n");
}