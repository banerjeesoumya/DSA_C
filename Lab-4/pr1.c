/*Write a program to create a single linked list of n nodes and perform the following menu
based operations on it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *NEXT;
};

void Insert (struct Node *Head, int pos);
void Delete (struct Node *Head, int pos);
int count (struct Node *temp);
void search (struct Node *Head, int key);
void sort (struct Node *temp);
struct Node* Reverse (struct Node *Head);
void traversal(struct Node *temp);

int main()
{
    struct Node *Head = NULL, *temp, *newNode;
    char ch;
    int pos, c, k;
    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1); 
        }

        printf("Enter data: ");
        scanf("%d", &newNode->INFO);
        newNode->NEXT = NULL;

        if (Head == NULL)
        {
            Head = newNode;
            temp = newNode;
        }
        else
        {
            temp->NEXT = newNode;
            temp = temp->NEXT;
        }

        printf("Do you have another data (Y/N): ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');
    printf ("\n");
    do
    {
        printf ("Linked List Operations :\n");
        printf ("1. Insert a node at specific position\n");
        printf ("2. Deletion of an element from specific position\n");
        printf ("3. Count nodes\n");
        printf ("4. Searching an element\n");
        printf ("5. Sorting the Linked List\n");
        printf ("6. Reversing the Linked List\n");
        printf ("7. Traverse the linked list\n");
        printf ("Enter your choice : \n");
        scanf (" %d", &c);
        switch (c)
        {
        case 1:
            printf ("Enter the postion where the insertion needs to take place : ");
            scanf ("%d", &pos);
            Insert(Head, pos);
            break;

        case 2:
            printf ("Enter the postion where the deletion needs to take place : ");
            scanf ("%d", &pos);
            Delete(Head, pos);
            break;

        case 3:
            printf ("No : of Nodes : %d\n", count (Head));
            //count (Head);
            break;

        case 4:
            printf ("Enter the element to be searched :- ");
            scanf ("%d", &k);
            search(Head, k);
            break;

        case 5:
            printf ("Sorting :-");
            sort(Head);
            break;

        case 6:
            printf ("Reversing :- ");
            Reverse(Head);
            break;

        case 7:
            printf ("Traverse the linked list : ");
            traversal(Head);
            break;
        
        default:
            printf ("Invalid Choice\n");
            break;
        }
    } while (c <= 7);
    
    // Free allocated memory to avoid memory leaks
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
    printf ("Enter the data to be inserted at the position : ");
    scanf ("%d", &New->INFO);
    New->NEXT = NULL;
    while (((pos - 1) != count) && (temp != NULL))
    {
        count ++;
        temp = temp->NEXT;
    }
    New->NEXT = temp->NEXT;
    temp->NEXT = New;
}

void Delete (struct Node *Head, int pos)
{
    struct Node *temp = Head;
    int count = 1;
    while (((pos - 1) != count) && (temp != NULL))
    {
        count ++;
        temp = temp ->NEXT;
    }
    temp->NEXT = temp->NEXT->NEXT;
}

int count (struct Node *temp)
{
    int c = 0;
    while (temp != NULL)
    {
        c ++;
        temp = temp->NEXT;
    }
    return c;
}

void search (struct Node *Head, int key)
{
    struct Node *temp = Head;
    int flag = 1, c = 0;
    while (temp != NULL)
    {
        if ((temp->INFO) == key)
        {
            flag = 0;
            break;
        }
        temp = temp->NEXT;c ++;
    }
        if (flag == 1)
            printf ("Not Found\n");
        else
            printf ("Found at position :- %d\n", (c + 1));
}

void sort (struct Node *temp)
{
    struct Node *temp1 = temp, *temp2;
    int temp3;
    if (temp1 == NULL)
    {
        return;
    }
    else
    {
        while (temp1 != NULL)
        {
            temp2 = temp1->NEXT;

            while (temp2 != NULL)
            {
                if ((temp1->INFO) > (temp2->INFO))
                {
                    temp3 = temp1->INFO;
                    temp1->INFO = temp2->INFO;
                    temp2->INFO = temp3;
                }
                temp2 = temp2->NEXT;    
            }
            temp1 = temp1->NEXT;
        }
    }
}

struct Node* Reverse (struct Node *Head)
{
    struct Node *temp1 = Head, *temp2, *temp3;
    if (count(temp1) == 2)
    {
       
        temp1->NEXT->NEXT = temp1;
        Head=temp1->NEXT;
        temp1->NEXT = NULL;
        
    }
    else if (count(temp1) == 3)
    {
        temp2 = temp1->NEXT;
        temp3= temp2->NEXT;

        temp1->NEXT = NULL;
        temp3->NEXT = temp2;
        temp2->NEXT=temp1;
        Head = temp3;
    }
    
    else
    {
        temp2 = temp1->NEXT;
        temp3 = temp2->NEXT;
        temp1->NEXT = NULL;
        
        while (temp3 != NULL)
        {
            temp2->NEXT = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3->NEXT;
        }

        temp2->NEXT = temp1;
        Head = temp2;
    }
    return Head;
}

void traversal(struct Node *temp)
{
    //printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d", temp->INFO);
        if (temp->NEXT != NULL) 
        {
            printf(" -> ");
        }
        temp = temp->NEXT;
    }
    printf("\n");
}
