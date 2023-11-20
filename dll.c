/*
Design, Develop and Implement a menu driven Program in C for the following operations on Doubly Linked List (DLL) of 
Professor Data with the fields: ID, Name, Branch, Area of Specialization

a. Create a DLL stack of N Professor’s Data.
Display the status of DLL and count the number of nodes in it.

b. Create a DLL queue of N Professor’s Data
Display the status of DLL and count the number of nodes in it. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count = 0;

struct node
{
    int id;
    char name[20],branch[10],aos[10];
    struct node *next;
    struct node *prev;
}*first=NULL,*last=NULL,*temp=NULL,*cur=NULL;

void create()
{
    int id;
    char name[20],branch[10],aos[10];
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter ID,NAME,BRANCH,AREA OF SPECIALIZATION:\n");
    scanf("%d%s%s%s",&id,name,branch,aos);
    strcpy(temp->aos,aos);
    strcpy(temp->name,name);
    strcpy(temp->branch,branch);
    temp->id=id;
    temp->next=NULL;
    temp->prev=NULL;
    count++;
}

void insert_end()
{
    if(first==NULL)
    {
        create();
        first=last=temp;
    }

    else
    {
        create();
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
}

void display()
{
    cur=first;
    if(cur==NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        printf("\nDetails of the professors are:\n");
        printf("ID\tName\tBranch\tArea of Specialization:\n");
        while(cur!=NULL)
        {
            printf("%d\t%s\t%s\t%s\n",cur->id,cur->name,cur->branch,cur->aos);
            cur=cur->next;
        }
        printf("No. of professors = %d\n\n",count);
    }
}

void delete_end()
{
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }

    else if(first->next==NULL)
    {
        printf("The deleted details of professors are:\n");
        printf("ID: %d\tName: %s\tBranch: %s\tArea of Spealization: %s\n",first->id,first->name,first->branch,first->aos);
        free(first);
        first=NULL;
    }

    else
    {
        temp=last;
        last=last->prev;
        last->next=NULL;
        printf("The deleted details of professors are:\n");
        printf("ID: %d\tName: %s\tBranch: %s\tArea of Spealization: %s\n",temp->id,temp->name,temp->branch,temp->aos);
        free(temp);
    }
    count--;
}

void delete_front()
{
    if(first==NULL)
    {
        printf("List is empty\n");
        return; 
    }
    temp=first;

    if(first->next==NULL)
    {
        printf("The deleted details of professors are:\n");
        printf("ID: %d\tName: %s\tBranch: %s\tArea of Spealization: %s\n",temp->id,temp->name,temp->branch,temp->aos);
        free(first);
        first=NULL;
    }

    else
    {
        first=first->next;
        first->prev=NULL;
        printf("The deleted details of professors are:\n");
        printf("ID: %d\tName: %s\tBranch: %s\tArea of Spealization: %s\n",temp->id,temp->name,temp->branch,temp->aos);
        free(temp);
    }
    count--;
}

void queuedemo()
{
    int ch,n,i;
    while(1)
    {
        printf("\n===== QUEUE of Professors using DLL =====\n");
        printf("1. Create a DLL of n professors\n");
        printf("2. Display the Queue of professors\n");
        printf("3. Insert End\n");
        printf("4. Delete Front\n");
        printf("5. Exit\n");
        printf("\nEnter choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter number of professors:\n");
                    scanf("%d",&n);
                    for(i=0; i<n; i++)
                    {
                        insert_end();
                    }
                break;
            case 2: display();
                break;
            case 3: insert_end();
                break;
            case 4: delete_front();
                break;
            case 5: exit(0);

            default: printf("Wrong choice\n");
        }
    }
}

void stackdemo()
{
    int ch,n,i;
    while(1)
    {
        printf("\n===== Stack of Professors using DLL =====\n");
        printf("1. Create DLL stack of n professors\n");
        printf("2. Display the stack of professors\n");
        printf("3. Insert End\n");
        printf("4. Delete End\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter number of professors: ");
                    scanf("%d",&n);
                    for(i=0; i<n; i++)
                    {
                        insert_end();
                    }
                break;
            case 2: display();
                break;
            case 3: insert_end();
                break;
            case 4: delete_end();
                break;
            case 5: exit(0);

            default: printf("Wrong choice\n");
        }
    }
}

int main()
{
    int ch;
    printf("1. Stack demo using professor data\n");
    printf("2. Queue demo using professor data\n");
    printf("Enter you choice: ");
    scanf("%d",&ch);

    if(ch == 1)
    {
        stackdemo();
    }
    if(ch == 2)
    {
        queuedemo();
    }
    return 0;
}