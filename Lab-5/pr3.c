#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};
void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\t%d\t%d\n", head->row, head->col, head->val);
        head = head->next;
    }
}

void sparse_add(struct node *head1, struct node *head2)
{
    struct node *new, *temp1, *temp2, *head3, *temp3;

    temp1 = head1;
    temp2 = head2;

    head3 = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        new = (struct node *)malloc(sizeof(struct node));
        if (head3 == NULL) // ll is empty
        {
            head3 = new;
            temp3 = new;
        }
         else
        {
            temp3->next = new;
            temp3 = temp3->next;
        }

        if (temp1->row > temp2->row)
        {
            temp3->row = temp2->row;
            temp3->col = temp2->col;
            temp3->val = temp2->val;
            temp2 = temp2->next;
        }
        else if (temp1->row < temp2->row)
        {
            temp3->row = temp1->row;
            temp3->col = temp1->col;
            temp3->val = temp1->val;
            temp1 = temp1->next;
        }
        else if (temp1->col > temp2->col)
        {
            temp3->row = temp2->row;
            temp3->col = temp2->col;
            temp3->val = temp2->val;
            temp2 = temp2->next;
        }
        else if (temp1->col < temp2->col)
        {
            temp3->row = temp1->row;
            temp3->col = temp1->col;
            temp3->val = temp1->val;
            temp1 = temp1->next;
        }
        else
         {
            temp3->row = temp1->row;
            temp3->col = temp1->col;
            temp3->val = temp1->val + temp2->val;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        temp3 = temp1;
        break;
    }
    while (temp2 != NULL)
    {
        temp3 = temp2;
        break;
    }
    traverse(head3);
}

int main()
{
    struct node *new, *temp1, *temp2, *head1, *head2;
    int r, c, val;
    new = (struct node *)malloc(sizeof(struct node));
    head1 = new;
    temp1 = new;
    printf("Enter the number  rows and columns of first sparse matrix\n ");
    scanf("%d%d", &r, &c);
    printf("Enter the number of non zero values\n");
    scanf("%d", &val);
    int x = val;
    for (int i = 1; i <= x; i++)
     {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter row and column position of non zero element\n");
        scanf("%d%d", &new->row, &new->col);
        printf("enter the non zero value\n");
        scanf("%d", &new->val);
        new->next = NULL;
        temp1->next = new;
        temp1 = temp1->next;
    }
    new = (struct node *)malloc(sizeof(struct node));
    head2 = new;
    temp2 = new;
    printf("Enter the number  rows and columns of second sparse matrix\n ");
    scanf("%d%d", &r, &c);
    printf("Enter the number of non zero values\n");
    scanf("%d", &val);
    x = val;
    for (int i = 1; i <= x; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter row and column position of non zero element\n");
        scanf("%d%d", &new->row, &new->col);
        printf("enter the non zero value\n");
        scanf("%d", &new->val);
        new->next = NULL;
        temp2->next = new;
        temp2 = temp2->next;
    }
    sparse_add(head1, head2);
    return 0;
}

//     // input,output
//     Enter the number  rows and columns of first sparse matrix
// 5 6
// Enter the number of non zero values
// 6
// Enter row and column position of non zero element
// 0 4
// enter the non zero value
// 9
// Enter row and column position of non zero element
// 1 1
// enter the non zero value
// 8
// Enter row and column position of non zero element
// 2 0
// enter the non zero value
// 4
// Enter row and column position of non zero element
// 2 3
// enter the non zero value
// 2
// Enter row and column position of non zero element
// 3 5
// enter the non zero value
// 5
// Enter row and column position of non zero element
// 4 2
// enter the non zero value
// 2
// Enter the number  rows and columns of second sparse matrix
//  5 6
// Enter the number of non zero values
// 6
// Enter row and column position of non zero element
// 0 4
