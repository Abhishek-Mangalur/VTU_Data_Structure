/* 
Design, Develop and Implement a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers
a. Create a BST of N Integers.
b. Traverse the BST in In-order, Pre-order and Post-order. 
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE insert_node(int item, NODE root)
{
    NODE cur, temp, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;

    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;

    while (cur != NULL)
    {
        prev = cur;
        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (item < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
    
    return root;
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    NODE root = NULL;
    int item, choice, n;
    for (;;)
    {
        printf("\n\n===== MENU =====\n");
        printf("1. Insert Node\n2. Inorder\n3. Pre-order\n4. Post-order\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter the no. of nodes\n");
                    scanf("%d", &n);
                    printf("Enter the item to be inserted\n");
                    for(int i=0; i<n; i++)
                    {
                        scanf("%d", &item);
                        root = insert_node(item, root);
                    }
                break;
            case 2: if (root == NULL)
                        printf("The tree is Empty\n");
                    else
                    {
                        printf("Inorder Series is:\n");
                        inorder(root);
                    }
                break;
            case 3: if (root == NULL)
                        printf("The tree is Empty\n");
                    else
                    {
                        printf("Pre-Order Series is:\n");
                        preorder(root);
                    }
                break;
            case 4: if (root == NULL)
                        printf("The tree is Empty\n");
                    else
                    {
                        printf("Post-Order Series is:\n");
                        postorder(root);
                    }
                break;
            case 5: exit(0);

            default: printf("Invalid Choice\n");
        }
    }
}
