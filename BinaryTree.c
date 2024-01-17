#include<stdio.h>
#include<stdlib.h>

//structure of tree node
struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};


//creating tree
struct Node* createTree(int data){
    struct Node* tree = (struct Node*)malloc(sizeof(struct Node));
    tree->data = data;
    tree->left=NULL;
    tree->right=NULL;
}


//to print or traverse from left to right
void postOrder(struct Node* rootNode){
    if(rootNode==NULL)
        return;
    postOrder(rootNode->left);
    postOrder(rootNode->right);
    printf("%d\t",rootNode->data);
}
//add comment
//to print or traverse first leaf left node then parent then right leaf node and so on
void inOrder(struct Node* rootNode){
    if(rootNode==NULL)
        return;
    inOrder(rootNode->left);
    printf("%d\t",rootNode->data);
    inOrder(rootNode->right);
}

void preOrder(struct Node* rootNode){
    if(rootNode==NULL)
        return;
    printf("%d\t",rootNode->data);
    preOrder(rootNode->left);
    preOrder(rootNode->right);
}
void main(){
    struct Node* rootNode = createTree(2);
    rootNode->left = createTree(3);
    rootNode->right = createTree(1);
    rootNode->left->left= createTree(5);
    
    rootNode->left->left->left=createTree(6);
    rootNode->left->left->right = createTree(4);
    rootNode->right->left = createTree(6);
    rootNode->right->right= createTree(4);

    postOrder(rootNode);

    printf("\nInOrder \n");
    inOrder(rootNode);

    printf("\nPreOrder \n");
    preOrder(rootNode);
}