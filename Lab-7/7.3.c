#include <stdlib.h>
#include <stdio.h>

int CQUEUE [100];
int FRONT = -1, REAR = -1, size;

void CQENQUEUE (int data);
int CQDEQUEUE ();
void display ();

int main ()
{
    int c;
    printf ("Enter the size of the queue :- ");
    scanf ("%d", &size);
    do
    {
        printf ("Circular Queue Operations :\n");
        printf ("1. Enqueue\n");
        printf ("2. Dequeue\n");
        printf ("3. IsEmpty\n");
        printf ("4. IsFull\n");
        printf ("5. Traverse\n");
        printf ("6. Exit\n");
        scanf ("%d", &c);
        switch (c)
        {
        case 1:
            int data;
            printf ("Enter the data to be enqueued :- ");
            scanf ("%d", &data);
            CQENQUEUE(data);
            break;
        
        case 2:
            int x = CQDEQUEUE();
            if (x != -99) {
                printf ("%d deleted from Circular Queue\n", x);
            }
            break;

        case 3:
            if ((FRONT == -1) && (REAR == -1))
            {
                printf ("True, CQUEUE is Empty\n");
            }
            else
            {
                printf ("False, CQUEUE is not Empty\n");
            }
            break;

        case 4: 
            if (((FRONT == (REAR + 1))) || ((FRONT == 0) && (REAR == (size - 1))))
            {
                printf ("True, CQUEUE is Full\n");
            }
            else
            {
                printf ("False, CQUEUE is not Full\n");
            }
            break;

        case 5:
            display();
            break;

        case 6:
            exit(504);
            break;

        default:
            printf ("Invalid Choice \n");
            break;
        }
    } while (c <= 6);    
}

void CQENQUEUE (int data)
{
    if (((FRONT == (REAR + 1))) || ((FRONT == 0) && (REAR == (size - 1))))
    {
        printf ("Overflow\n");
        return;
    }
    else if ((FRONT == -1) && (REAR == -1))
    {
        FRONT = REAR = 0;
        CQUEUE[REAR] = data;
    }
    else
    {
        REAR = (REAR + 1) % size;
        int p = REAR;
        CQUEUE[REAR] = data;
    }
}

int CQDEQUEUE ()
{
    int x;
    if ((FRONT == -1) && (REAR == -1))
    {
        printf ("Underflow\n");
        return -99;
    }
    else if (FRONT == REAR)
    {
        x = CQUEUE[FRONT];
        FRONT = REAR = -1;
        int Q = FRONT;
        //return x;
    }
    else
    {
        x = CQUEUE[FRONT];
        FRONT = (FRONT + 1) % size;
        //return x;
    }
    return x;
}

void display ()
{
    int f = FRONT, r = REAR;
    if ((FRONT == -1) && (REAR == -1))
    {
        printf ("CQUEUE is Empty, nothing to print\n");
    }
    else
    {
        int i;
        for (i = FRONT; i != (REAR); i = ((i + 1) % size))
        {
            int m = ((i + 1) % size);
            int n = i;
            printf ("%d ", CQUEUE[i]);
        }
        printf ("%d", CQUEUE[i]);
    }
    printf("\n");    
}