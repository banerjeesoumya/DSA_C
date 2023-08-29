/*WAP to create a 1-D array of n elements and perform the following menu based operations
using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array
*/

#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];

void InsertAtLocation (int el, int pos, int *size);
void DeleteAtLocation (int pos, int *size);
void LinearSearch (int el, int size);

int main ()
{
    int ch, el, pos, size;
    printf ("Enter the size of the array \n");
    scanf ("%d", &size);

    printf ("Enter the elements of the array \n");
    for (int i = 0; i < size; i ++)
    {
        scanf ("%d", &arr[i]);
    }

    while (1)
    {
        /* code */
        printf ("\nArray Operations :\n");
        printf ("1.Insert at given location\n");
        printf ("2.Delete from given location\n");
        printf ("3.Perform Linear Search\n");
        printf ("4.Perform Traversal of the Array\n");
        printf ("Enter your choice : ");
        scanf ("%d", &ch);

        switch (ch)
        {
            case 1:
                printf ("Enter the element to be inserted: ");
                scanf ("%d", &el);
                printf ("Enter the postion where the element needs to be inserted: ");
                scanf ("%d", &pos);
                InsertAtLocation (el, pos, &size);
                break;

            case 2:
                printf ("Enter the postion from where the element needs to be deleted: ");
                scanf ("%d", &pos);
                DeleteAtLocation (pos, &size);
                break;

            case 3:
                printf ("Enter the element to be searched: ");
                scanf ("%d", &el);
                LinearSearch (el, size);
                break;

            case 4:
                printf ("Traversal of the array: ");
                for (int i = 0; i < size; i ++)
                {
                    printf ("%d ", arr[i]);
                }
                break;
            default:
                printf ("Invalid Choice\n");
                break;
        }
    }    
}

void InsertAtLocation (int el, int pos, int *size)
{
    if ((pos < 1) || (pos > (*size + 1)))
    {
        printf ("Invalid position");
        return;
    }
    else
    {
        for (int i = (*size - 1); i >= (pos- 1); i --)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = el;
    }
    (*size) ++;
}

void DeleteAtLocation (int pos, int *size)
{
    if ((pos < 1) && (pos > (*size)))
    {
        printf ("Invalid position\n");
        return;
    }

    for (int i = pos - 1; i < (*size - 1); i ++)
    {
        arr[i] = arr[i + 1];
    }
    (*size) --;
}

void LinearSearch (int el, int size)
{
    int flag = 0;
    for (int i = 0; i < (size); i ++)
    {
        if (arr[i] == el)
        {
            flag = 1;
            printf ("Element found at postion %d\n", (i + 1));
            break;
        }
    }
    if (flag == 0)
        printf ("Element not found\n");
}



