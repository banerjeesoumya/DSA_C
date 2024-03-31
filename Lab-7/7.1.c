/*Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.*/
#include <stdio.h>
int QUEUE [100];
int FRONT = -1, REAR = -1, size;

void ENQUEUE (int data);
int DEQUEUE ();
void display ();

int main ()
{
    int c;
    printf ("Enter the size of the queue :- ");
    scanf ("%d", &size);
    do
    {
        printf ("Queue Operations :\n");
        printf ("1. Enqueue\n");
        printf ("2. Dequeue\n");
        printf ("3. IsEmpty\n");
        printf ("4. IsFull\n");
        printf ("5. Traverse\n");
        printf ("Enter your choice: ");
        scanf ("%d", &c);
        switch (c)
        {
        case 1:
            int data;
            printf ("Enter the data to be enqueued : ");
            scanf ("%d", &data);
            ENQUEUE (data);
            break;

        case 2:
            int x = DEQUEUE();
            printf ("%d deleted from Queue\n", x);
            break;

        case 3:
            if ((FRONT == -1) && (REAR == -1))
            {
                printf ("True, Queue is Empty\n");
            }
            else
            {
                printf ("False, Queue is not Empty\n");
            }
            break;
            
        case 4:
            if (REAR == (size - 1))
                printf ("True, Queue is Full\n");
            else
                printf ("False, Queue is not Full\n");
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

void ENQUEUE (int data)
{
    if  (REAR == (size - 1))
    {
        printf ("Overflow\n");
        return;
    }
    else if ((FRONT == -1) && (REAR == -1))
    {
        REAR ++;
        FRONT ++;
        QUEUE[REAR] = data;
    }
    else
    {
        REAR ++;
        QUEUE[REAR] = data;
    }
}

int DEQUEUE ()
{
    if ((FRONT == -1) && (REAR == -1))
    {
        printf ("Underflow\n");
        return 0;
    }
    else if (FRONT == REAR)
    {
        int x = QUEUE[FRONT];
        FRONT = REAR = -1;
        return x;
    }
    else
    {
        int x = QUEUE[FRONT];
        FRONT ++;
        return x;
    }
}

void display ()
{
    for (int i = FRONT; i <= REAR; i ++)
    {
        printf ("%d", QUEUE[i]);
        if (i != REAR)
        {
            printf (" , ");
        }
    }
    printf ("\n");
}