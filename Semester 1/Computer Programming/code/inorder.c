#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *leftChild, *rightChild;
} node;

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

node *newNode(int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        fprintf(stderr, "Memory failure \n ");
        exit(1);
    }
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}

node *insert(node *root, int data)
{

    if (root == NULL)
        root = newNode(data);
    else
    {
        if (data < root->data)
            root->leftChild = insert(root->leftChild, data);
        else
            root->rightChild = insert(root->rightChild, data);
    }

    return root;
}
int main()
{

    struct node *bst = NULL;
    bst = insert(bst, 70);
    insert(bst, 10);
    insert(bst, 90);
    insert(bst, 40);
    insert(bst, 30);
    insert(bst, 60);
    inorder(bst);

    return 0;
}