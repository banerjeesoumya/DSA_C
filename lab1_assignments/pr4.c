/*Write a menu driven program to create a structure to represent complex number and
perform the following operation using function :
1. addition of two complex number (call by value)
2. multiplication of two complex number (call by address)
*/

#include <stdio.h>
typedef struct complex_num
{
    float real;
    float imagn;
} complex_num;

complex_num add(complex_num n1,complex_num n2);
complex_num mult(complex_num n1,complex_num n2);

complex_num add(complex_num n1,complex_num n2)
{
    complex_num sum;
    sum.real= n1.real + n2.real;
    sum.imagn=n1.imagn + n2.imagn;
    return (sum);
}

complex_num mult(complex_num n1,complex_num n2)
{
    complex_num prod;
    prod.real= (n1.real * n2.real)-(n1.imagn * n2.imagn);
    prod.imagn=(n1.real * n2.imagn)-(n2.real * n1.imagn);
    return (prod);
}

int main()
{
    complex_num n1,n2,res1,res2;
    int c;
    printf("Enter the real and complex parts for 1st number \n");
    scanf("%f%f",&n1.real,&n1.imagn);
    printf("Enter the real and complex parts for 2nd number \n");
    scanf("%f%f",&n2.real,&n2.imagn);
    printf("\nChoose an appropriate option for an operation to perform:\n1.ADDITION\n2.MULTIPLICATION\nChoose an appropriate option:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        res1=add(n1,n2);
        printf("The sum is %f + %f i.",res1.real,res1.imagn);
        break;

        case 2:
        res2=mult(n1,n2);
        printf("The product is %f + %f i.",res2.real,res2.imagn);
        break;

        default:
        printf("Invalid Choice!");
    }
    return 0;
}