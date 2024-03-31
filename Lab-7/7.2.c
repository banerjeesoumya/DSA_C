#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *NEXT;
};

void ENQUEUE (int data);
int DEQUEUE ();
void display();

struct Node *FRONT = NULL, *REAR = NULL;

int main ()
{
    int c;
    do
    {
        printf ("Queue Operations :\n");
        printf ("1. ENQUEUE\n");
        printf ("2. DEQUEUE\n");
        printf ("3. IsEmpty\n");
        printf ("4. Traverse\n");
        printf ("5. Exit\n");
        printf ("Enter your choice : ");
        scanf ("%d", &c);
        switch (c)
        {
        case 1:
            int data;
            printf ("Enter the data to be enqueue to the QUEUE : ");
            scanf ("%d", &data);
            ENQUEUE (data);
            break;

        case 2:
            int x = DEQUEUE();
            if (x != -99) {
                printf ("%d deleted from Circular Queue\n", x);
            }
            break;

        case 3:
            if ((FRONT == NULL) && (REAR == NULL))
                printf ("True, the queue is Empty\n");
            else
                printf ("False, the queue is not Empty\n");
            break;

        case 4:
            display();
            break;

        case 5:
            exit(404);
            break;

        default:
            printf ("Invalid Choice\n");
            break;
        }
    } while (c <= 4);
}

void ENQUEUE (int data)
{
    struct Node *New;
    struct Node *f = FRONT, *r = REAR; //these variables are kept to understand what are the current values of FRONT and REAR while debugging.
    New = (struct Node *)malloc(sizeof(struct Node));
    New->INFO = data;
    New->NEXT = NULL;
    if ((FRONT == NULL) && (REAR == NULL))
    {
        FRONT = New;
        REAR = New;
    }
    else
    {
        REAR->NEXT = New;
        REAR = New;
    }
}

int DEQUEUE ()
{
    int x;
    struct Node *f = FRONT, *r = REAR; //these variables are kept to understand what are the current values of FRONT and REAR while debugging.
    if ((FRONT == NULL) && (REAR == NULL)) {
        printf ("Underflow\n");
    }
    else if (FRONT == REAR)
    {
        x = FRONT->INFO;
        FRONT = NULL;
        REAR = NULL;
        free(FRONT);
    }
    else
    {
        x = FRONT->INFO;
        struct Node *ptr = FRONT;
        FRONT = FRONT->NEXT;
        free(ptr);
    }
    
    return x;
}

void display()
{
    struct Node *temp = FRONT;
    while (temp != NULL)
    {
        printf ("%d", temp->INFO);
        if (temp->NEXT != NULL)
        {
            printf (" , ");
        }
        temp = temp->NEXT;
    }
    printf("\n");
}