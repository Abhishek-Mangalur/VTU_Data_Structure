/* 
Design, Develop and Implement a menu driven Program in C for the following Array operations
a. Inserting an Element (ELEM) at a given valid Position (POS)
b. Deleting an Element at a given valid Position POS)
c. Display of Array Elements
d. Exit. 
*/

#include <stdio.h>
#include <stdlib.h>

int a[20];
int n = 0;

void create()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements for the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display()
{
    if (n == 0)
    {
        printf("Array list is empty\n");
    }
    else
    {
        printf("The array elements are:\n");
        for (int i = 0; i < n; i++)
            printf("%d\t", a[i]);
    }
}

void insert()
{
    int pos, value;
    printf("Enter the index position for the new element: ");
    scanf("%d", &pos);
    printf("Enter the element to be inserted : ");
    scanf("%d", &value);
    for (int i = n - 1; i >= pos; i--)
        a[i + 1] = a[i];
    a[pos] = value;
    n = n + 1;
}

void delete()
{
    int pos, value;
    if (n == 0)
    {
        printf("Array list is empty\n");
    }
    else
    {
        printf("\nEnter the index position to delete an element: ");
        scanf("%d", &pos);
        if(pos > n)
        {
            printf("Array size limit is %d ", n);
            printf("So you have to enter within the limit\n");
        }
        else
        {
            value = a[pos];
            for (int i = pos + 1; i < n; i++)
                a[i - 1] = a[i];
            n = n - 1;
            printf("The deleted element is = %d\n", value);
        }
    }
    
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n\nA program to perform array operation\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: create();
                break;
            case 2: display();
                break;
            case 3: insert();
                break;
            case 4: delete(); 
                break;
            case 5: exit(0);
            
            default: printf("Invalid choice\n");
        }
    }
}
