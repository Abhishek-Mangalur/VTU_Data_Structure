/* 
Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate Overflow and Underflow situations on Stack
d. Display the status of Stack
e. Exit 
*/

#include <stdio.h>
#include <stdlib.h>
#define max_size 5

int stack[max_size];
int top = -1;

void push()
{
    int item;
    if (top == max_size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to insert in an array\n");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The popped element : %d", stack[top--]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The stack elements are :\n\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    printf("\n");
}

void main()
{
    int choice;
    for(;;)
    {
        printf("\n====== STACK OPERATIONS ======\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);

            default: printf("Invalid choice\n");
        }
    }
}