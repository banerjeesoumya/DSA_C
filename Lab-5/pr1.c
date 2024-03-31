/*5.1 Write a program to create a double linked list and perform the following menu based
operations on it:
i. insert an element at specific position
ii. delete an element from specific position
iii. Traverse the list*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *NEXT;
    struct Node *PREV;
};

void traversal (struct Node *temp);
void Insert (struct Node *Head, int pos);
void Delete (struct Node *Head, int k);

int main ()
{
    struct Node *Head = NULL, *temp, *newNode;
    char ch;
    int pos, c, k;
    do 
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf ("Memory Allocation Failed. \n");
            exit(1);
        }

        printf ("Enter the data : ");
        scanf ("%d", &newNode->INFO);
        newNode->NEXT = NULL;
        newNode->PREV = NULL;

        if (Head == NULL)
        {
            Head = newNode;
            temp = newNode;
        }
        else
        {
            temp->NEXT = newNode;
            newNode->PREV = temp;
            temp = temp->NEXT;
        }

        printf ("Do you have another data (Y/N): ");
        scanf (" %c", &ch);
    }
    while ((ch == 'Y') || (ch == 'y'));
    printf ("\n");
    do
    {
        printf ("Double Linked List Operations : \n");
        printf ("1. Insert a node at specific position \n");
        printf ("2. Delete an element from specific position \n");
        printf ("3. Traverse the list \n");
        printf ("Enter your choice : \n");
        scanf (" %d", &c);

        switch (c)
        {
        case 1:
            printf ("Enter the position where the insertion needs to take place : ");
            scanf ("%d", &pos);
            Insert (Head, pos);
            break;
        
        case 2:
            printf ("Enter the position where the deletion needs to take place : ");
            scanf ("%d", &pos);
            Delete (Head, pos);
            break;

        case 3:
            printf ("Traverse the linked list : ");
            traversal(Head);
            break;

        default:
            printf ("Invalid Choice \n");
            break;
        }
    } while (c <= 3);
    
    while (Head != NULL)
    {
        temp = Head;
        Head = Head->NEXT;
        free(temp);
    }
    return 0;
}

void Insert (struct Node *Head, int pos)
{
    struct Node *New, *temp;
    int count = 1;
    temp = Head;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf ("Enter the data to be inserted at the position :- ");
    scanf ("%d", &New->INFO);
    New->NEXT = NULL;
    while (((pos - 1) != count) && (temp != NULL))
    {
        temp = temp->NEXT;
        count ++;
    }
    New->NEXT = temp->NEXT;
    temp->NEXT->PREV = New;
    New->PREV = temp;
    temp->NEXT = New;
}

void Delete (struct Node *Head, int k)
{
    struct Node *temp;
    temp = Head;
    int count = 1;
    while ((count != k) && (temp != NULL))
    {
        temp = temp->NEXT;
        count ++;
    }
    temp->PREV->NEXT = temp->NEXT;
    temp->NEXT->PREV = temp->PREV;
}

void traversal (struct Node *temp)
{
    while (temp != NULL)
    {
        printf ("%d", temp->INFO);
        if (temp->NEXT != NULL)
        {
            printf(" -> ");
        }
        temp = temp->NEXT;
    }
    printf ("\n");
}
