#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNewNode(int val)
{
    struct Node *root = malloc(sizeof(struct Node));

    root->value = val;
    root->left = NULL;
    root->right = NULL;
};

void insertLeft(struct Node* root, int val){
    root->left = createNewNode(val);
}

void insertRight(struct Node* root, int val){
    root->right = createNewNode(val);
};

void preorderTraversal(struct Node* root){
    if(root!=NULL){
        printf("%d ", root->value);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->value);
    }
}

int main(){
    struct Node* root = createNewNode(1);

    insertLeft(root, 2);
    insertRight(root, 3);  

    insertRight( root->left, 4);
    insertLeft(root->right, 5); 

    insertLeft( root->left->right, 6);
    insertRight( root->left->right, 7);

    insertRight(root->right->left, 8);

    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
}
