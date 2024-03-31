/*Write a menu driven program to implement Deques (both Inputrestricted and outputrestricted)
and performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using
static array.

Sample Input/Output:
Input restricted Dequeue Menu
1. Insert at right
2. Delete from left
3. Delete from right
4. Display
5.Quit */

#include <stdio.h>
#include <stdlib.h>
int QUEUE[100];
int size, FRONT = -1, REAR;

void Insert_Rear(int data);
void Insert_Front(int data);
int Front_Delete();
int Rear_Delete();
void display();

int main ()
{
    int ch1, ch2, ch3;
    printf ("Enter the size of the queue :- ");
    scanf ("%d",  &size);
    REAR = size - 1;
    do
    {
        printf ("1. Input restricted Queue\n");
        printf ("2. Output restricted Queue\n");
        printf ("Which is the type of queue you want to implement :- ");
        scanf ("%d", &ch1);
        switch (ch1)
        {
            case 1:
                do
                {
                    printf ("Input restricted Dequeue Menu :-\n");
                    printf ("1. Insert at right\n");
                    printf ("2. Delete from left\n");
                    printf ("3. Delete from right\n");
                    printf ("4. Display\n");
                    printf ("5. Quit\n");
                    printf ("Enter your choice: ");
                    scanf ("%d", &ch2);
                    switch (ch2)
                    {
                        case 1:
                            int data;
                            printf ("Enter the data to be inserted at right");
                            scanf ("%d", &data);
                            Insert_Rear(data);
                            break;

                        case 2:
                            int x1 = Front_Delete();
                            if (x1 != -99)
                            {
                                printf ("%d deleted from QUEUE\n", x1);
                            }
                            break;

                        case 3:
                            int x2 = Rear_Delete();
                            if (x2 != -99)
                            {
                                printf ("%d deleted from QUEUE\n", x2);
                            }
                            break;

                        case 4:
                            display();
                            break;

                        case 5:
                            exit(503);
                            break;

                        default:
                            printf ("Invalid Choice\n");
                            break;
                    }//end of switch()
                }while (ch2<= 5);//end of do-while for input restricted queue
                break;

            case 2:
                do
                {
                    printf ("Output restricted Dequeue Menu :-\n");
                    printf ("1. Insert at right\n");
                    printf ("2. Insert at left\n");
                    printf ("3. Delete from left\n");
                    printf ("4. Display\n");
                    printf ("5. Quit\n");
                    printf ("Enter your choice: ");
                    scanf ("%d", &ch3);
                    switch (ch3)
                    {
                        case 1:
                            int data1;
                            printf ("Enter the data to be inserted at right");
                            scanf ("%d", &data1);
                            Insert_Rear(data1);
                            break;

                        case 2:
                            int data2;
                            printf ("Enter the data to be inserted at left");
                            scanf ("%d", &data2);
                            Insert_Front(data2);
                            break;

                        case 3:
                            int x3 = Front_Delete();
                            if (x3 != -99)
                            {
                                printf ("%d deleted from QUEUE\n", x3);
                            }
                            break;

                        case 4:
                            display();
                            break;

                        case 5:
                            exit(503);
                            break;

                        default:
                            printf ("Invalid Choice\n");
                            break;
                    }//end of internal switch()
                }while (ch3<= 5);//end of do-while for output restricted queue
                break;

            default:
                printf ("Invalid Choice\n");
                break;
        }//end of external switch
    }while(ch1 <= 2);//end of main do-while
}

void Insert_Rear(int data)
{
    if (FRONT == REAR)
    {
        printf ("Overflow\n");
        return;
    }
    else
    {
        QUEUE[REAR] = data;
        REAR = (REAR - 1 + size) % size;
    }
}

void Insert_Front(int data)
{
    if (FRONT == REAR)
    {
        printf ("Overflow\n");
        return;
    }
    else
    {
        FRONT = (FRONT + 1) % size;
        QUEUE[FRONT] = data;
    }
}

int Front_Delete()
{
    int x;
    if (FRONT == -1)
    {
        printf ("Underflow\n");
        return -99;
    }
    else
    {
        x = QUEUE[FRONT];
        FRONT = FRONT - 1;
    }
    return x;
}

int Rear_Delete()
{
    int x;
    if (REAR == (size - 1))
    {
        printf ("Underflow\n");
        return -99;
    }
    else
    {
        x = QUEUE[REAR];
        REAR = REAR + 1;
    }
    return x;
}

void display()
{
    if ((FRONT == -1) && (REAR == (size - 1)))
    {
        printf ("Queue is empty\n");
        return;
    }

    for (int i = FRONT; i != (REAR + 1) % size; i = (i + 1) % size)
    {
        printf ("%d ", QUEUE[i]);
    }
    printf("\n");
}