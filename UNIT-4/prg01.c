/* Enrollment no- 92500527148 */
/*1. Write a program to create a binary tree . Traverse tree in preorder ,
postorder and inorder. */



#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data)
{
    struct Node *newNode;
    newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode-> data=data;
    newNode-> left=NULL;
    newNode-> right=NULL;

    return newNode;
};
void preorder(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void postorder(struct Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void main()
{

    struct Node *root=createNode(9);

    root->left=createNode(8);
    root->right=createNode(7);

    root->left->left=createNode(6);
    root->left->right=createNode(5);

    printf("Preorder:");
    preorder(root);


    printf("\nInorder:");
    inorder(root);


    printf("\nPostorder:");
    postorder(root);

}

