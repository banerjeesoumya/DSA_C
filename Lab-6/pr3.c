/*Write a program to convert infix expression to postfix operation using stack.*/

#include <stdio.h>

char STACK[100];
int TOP = -1;

void Push (char item)
{
    TOP ++;
    STACK[TOP] = item;
}

char Pop ()
{
    char item;
    if (TOP == -1)
        return -1;
    else
    {
        item = STACK[TOP];
        TOP --;
        return item;
    }
}