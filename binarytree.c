#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   int data;
   struct node *left,*right;
}node;

node * root = NULL;

node *createNode(){
    int val;
    printf("enter the value -1 for no node \n");
    scanf("%d",&val);
    if(val == -1)
      return NULL;
    node * newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    printf("enter the left child of %d ",val);
    newNode->left = createNode();
    printf("enter the right child of %d ",val);
    newNode->right = createNode();
    return newNode;
}

void preorder(node * root){
    if(!root){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

node* rightMost(node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}


node* deleteNode(node* root, int val) {
    if (!root)
        return NULL;

    if (root->data == val) {
        // No child
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        // One child
        if (!root->right) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        if (!root->left) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        // Two children
        node* rightmost = rightMost(root->left);
        rightmost->right = root->right;
        node* temp = root->left;
        free(root);
        return temp;
    }

    root->left = deleteNode(root->left, val);
    root->right = deleteNode(root->right, val);
    return root;
}

int main()
{
    int ch,val;
    while(1)
    {
        printf("\n---Binary Tree---\n1.create\n2.preorder\n3.postorder\n4.inorder\n5.exit\n6.Delete\nEnter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            root=createNode();
            break;
        case 2:
            preorder(root);
            break;
        // case 3:
        //     postorder(root);
        //     break;
        // case 4:
        //     inorder(root);
        //     break;
        // case 5:
        //     exit(0);
        case 6:
            printf("Enter Value:");
            scanf("%d",&val);
            root=deleteNode(root,val);
            break;
        default:
            printf("Invalid!\n");
            break;
        }
    }
    
    return 0;
}