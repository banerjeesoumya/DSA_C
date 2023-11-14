/*Write a program to create a structure to store the information of n number of Employees.
Employee’s information includes data members: Emp-id, Name, Designation, basic_salary,
hra%, da%. Display the information of employees with gross salary. Use array of structure.
*/

#include <stdio.h>

// Structure to store employee information
struct Employee 
{
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
    float grossSalary;
};

int main() 
{
    int n;
    // Input the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    // Declare an array of structures to store employee information
    struct Employee employees[n];

    // Input employee information
    for (int i = 0; i < n; i++) 
    {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hraPercentage);
        printf("DA Percentage: ");
        scanf("%f", &employees[i].daPercentage);

        // Calculate the gross salary
        employees[i].grossSalary = employees[i].basicSalary + (employees[i].basicSalary * employees[i].hraPercentage / 100) + (employees[i].basicSalary * employees[i].daPercentage / 100);
    }

    // Display employee information with gross salary
    printf("\nEmployee Information with Gross Salary:\n");
    printf ("\n");
    for (int i = 0; i < n; i++) 
    {
        printf ("Name: %s\n", employees[i].name);
        printf ("Designation: %s\n", employees[i].designation);
        printf ("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf ("HRA(Percentage): %.2f\n", employees[i].hraPercentage);
        printf ("DA(Percentage): %.2f\n", employees[i].daPercentage);
        printf ("Gross Salary: %.2f\n", employees[i].grossSalary);
        printf ("\n");
        //printf("%-8d%-15s%-14s%-15.2f%-12.2f\n", (i + 1), employees[i].name, employees[i].designation, employees[i].basicSalary, employees[i].grossSalary);
    }
    return 0;
}