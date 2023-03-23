/* 
Design, Develop and Implement a menu driven Program in C for the following Array Operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Exit. 
*/

#include<stdio.h>
#include<stdlib.h>

int a[20];
int n = 0;

void create()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements to array:\n");

    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
}

void display()
{
    printf("The array elements are:\n");
    for(int i=0; i<n; i++)
        printf("%d\t ",a[i]);
    printf("\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nA program to perform array operation\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create();
                break;
            case 2: if(n == 0)
                        printf("Array List is Empty\n");
                    else
                        display();
                break;
            case 3: exit (0);

            default: printf("Invalid choice\n");
        }
    }
}