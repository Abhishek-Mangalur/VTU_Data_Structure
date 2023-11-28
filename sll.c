/*
1. Singly Linked List (SLL) of Integer Data
a. Create a SLL stack of N integer.
b. Display of SLL
c. Linear search. Create a SLL queue of N Students Data Concatenation of two SLL of integers. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node * NODE;
struct nodes
{
    char usn[100],name[100],branch[100];
    struct nodes *next;
};
typedef struct nodes * NODES;

NODES insertRear(NODES first)
{
    NODES temp,cur;
    char usn[100],branch[100],name[100];
    temp=(NODES)malloc(sizeof(struct nodes));
    printf("Enter student's name,usn,branch respectively\n");
    scanf("%s%s%s",name,usn,branch);
    strcpy(temp->name,name);
    strcpy(temp->usn,usn);
    strcpy(temp->branch,branch);
    temp->next=NULL;
    if(first==NULL)
        return temp;
    cur = first;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next=temp;
    return first;
}

NODES DeleteFront(NODES first)
{
    NODES temp = first;
    if(first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    printf("\nDeleted students data is\n");
    printf("%s\t%s\t%s\t",first->name,first->usn,first->branch);
    first = temp->next;
    free(temp);
    return first;
}

void displayq(NODES first)
{
    NODES cur = first;
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("\nStudents data is\nname\t\tusn\t\tbranch\t\n------\t\t------\t\t-------\t\n");
    while(cur!=NULL)
    {
        printf("%s\t\t%s\t\t%s\t\n",cur->name,cur->usn,cur->branch);
        cur = cur->next;
    }
}

NODES createq()
{
    int n;
    NODES temp = NULL;
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter student %d details\n",i+1);
        temp = insertRear(temp);
    }
    return temp;
}

NODE insertFront(NODE first,int item)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = NULL;
    if(first==NULL)
        return temp;
    temp->link = first;
    first = temp;
    return first;
}

NODE deleteFront(NODE first)
{
    NODE temp = first;
    if(first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    printf("Deleted item is %d\n",temp->info);
    first = temp->link;
    free(temp);
    return first;
}

void display(NODE first)
{
    NODE cur = first;
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur = cur->link;
    }
}

void linearSearch(NODE first)
{
    NODE cur = first;
    int key, count = 0;
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        printf("Enter the key to be searched:\n");
                    scanf("%d", &key);
    }
    
    while(cur!=NULL&&key!=cur->info)
    {
        cur = cur->link;
        count++;
    }
    if(cur==NULL)
    {
        printf("Unsuccessful search\n");
        return;
    }
    printf("Element found at location %d\n",count+1);
    return;
}

NODE create()
{
    int n,item;
    NODE temp = NULL;
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter %d item\n",i+1);
        scanf("%d",&item);
        temp = insertFront(temp,item);
    }
    return temp;
}

NODE concatenate(NODE first,NODE second)
{
    NODE cur = first;
    if(first == NULL)
        return second;
    while(cur->link!=NULL)
        cur = cur->link;
    cur->link = second;
    return first;
}

void stack()
{
    int ch, n, i, item;
    NODE first=NULL,second=NULL;
    printf("\n==== Stack of Integers using SLL ====\n");

    while (1)
    {
        printf("\n============= MENU =============\n");
        printf("1. Create SLL stack of integers\n2. Display\n3. Insert Front\n4. Delete Front\n5. Linear Search\n6. Concatenation of 2 lists\n7. Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("Enter details of first linked list\n");
                    first = create();
                break;
            case 2: display(first);
                break;
            case 3: printf("Enter item to insert at first\n");
                    scanf("%d",&item);
                    first = insertFront(first,item);
                break;
            case 4: first = deleteFront(first);
                break;
            case 5: linearSearch(first);
                break;
            case 6: printf("Enter details of second linked list\n"); 
                    second = create();
                    first = concatenate(first,second);
                break;
            case 7: exit(0);

            default: printf("invalid choice");
        }
    }
}

void queue()
{
    int ch, n, i, key, item;
    NODES first=NULL;
    printf("\n==== Queue of Student's Data SLL ====\n");

    while (1)
    {
        printf("\n=============== MENU ===============\n");
        printf("1. Create SLL queue of students data\n2. Display\n3. Insert Rear\n4. Delete Front\n5. Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: first = createq();
                break;
            case 2: displayq(first);
                break;
            case 3: first = insertRear(first);
                break;
            case 4: first = DeleteFront(first);
                break;
            case 5: exit(0);

            default: printf("invalid choice");
        }
    }
}

int main()
{
    int choice;
    printf("\n1. SLL stack of integers\n2. SLL queue of students data\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: stack();
        break;
        case 2: queue();
    }
}