/* Enrollment no- 92500527148 */
/*2. Write  a program to perform following operations on Binary search
tree:
a.insert delete
b.height of the tree
c.total no. of nodes in the tree  */

/* Find inorder of this 30,10,50,5,35,15  in BST = 5,10,15,30,35,50    */

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

    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode-> data=data;
    newNode-> left=NULL;
    newNode-> right=NULL;

    return newNode;
}

 struct Node* insert(struct Node* root, int data) {
 if(root==NULL)
    return createNode(data);

 if(data<root->data)
    root->left=insert(root->left,data);

else if(data>root->data)
    root->right=insert(root->right,data);

    return root;
 }

 struct Node* minValueNode(struct Node* node) {
  struct Node* current =node;

  while(current->left!=NULL)
    current=current->left;

  return current;

 }

 struct Node* deleteNode(struct Node* root, int data) {
 if(root==NULL)
    return root;

 if(data<root->data)
    root->left=deleteNode(root->left,data);

else if(data>root->data)
    root->right=deleteNode(root->right,data);

else {
    if(root->left==NULL){
      struct Node* temp=root->right;
      free(root);
      return temp;
    }
    else if(root->right==NULL) {
        struct Node* temp=root->left;
        free(root);
        return temp;
    }

    struct Node* temp=minValueNode(root->right);
    root->data =temp->data;
    root->right=deleteNode(root->right,temp->data);
}

    return root;
 }

 int height(struct Node* root) {
   if(root==NULL)
     return 0;

   int leftHeight=height(root->left);
   int rightHeight= height(root->right);

   if(leftHeight>rightHeight)
     return leftHeight + 1;
   else
     return rightHeight + 1;
 }

 int countNodes(struct Node* root) {
 if(root==NULL)
    return 0;

   return 1 +countNodes(root->left)+countNodes(root->right);

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

int main()
{

    struct Node* root=NULL;

    int choice,value;

    while(1) {
        printf("\n\n ---Binary search Tree---");
        printf("\n1 Insert:");
        printf("\n2 Delete:");
        printf("\n3 height of Node:");
        printf("\n4 Count of Nodes:");
        printf("\n5 Display (Inorder)");
        printf("\n6 Exit:");

        printf("\n Enter your Choice:");
        scanf("%d",&choice);

        switch(choice) {
           case 1:
                printf("\n Enter Value:");
                scanf("%d",&value);
                root=insert(root,value);
                break;
           case 2:
                printf("\n Enter Value  to delete:");
                scanf("%d",&value);
                root=deleteNode(root,value);
                break;
           case 3:
                printf("\n Height of tree =%d",height(root));
                break;

            case 4:
                printf("\n Count  of Nodes =%d",countNodes(root));
                break;
            case 5:
                printf("\n Inorder:");
                inorder(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice");
        }
    }
      return 0;
}

