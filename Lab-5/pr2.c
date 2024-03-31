#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *NEXT;
};

struct Node* create (struct Node *Head, int k);
void print (struct Node *temp);


int main ()
{
    int k;
    struct Node *Head1;
    printf ("Enter the no:of nodes :- ");
    scanf ("%d", &k);
    Head1 = create (Head1, k);
    printf ("Circular Linked List :- ");
    print (Head1);
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

        printf ("Enter the info of Node %d :- ", i);
        scanf ("%d", &New->INFO);
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
    temp->NEXT = Head;
    return Head;
}

void print (struct Node *temp)
{
    struct Node *ptr = temp;
    printf ("%d, ", temp->INFO);
    temp = temp->NEXT;
    while (temp != ptr)
    {
        printf ("%d", temp->INFO);
        if (temp->NEXT != ptr)
        {
            printf (" , ");
        }
        temp = temp->NEXT;
    }
    printf ("\n");
}

