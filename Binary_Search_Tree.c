#include<stdio.h>
#include<stdlib.h>

//structure of tree node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

//creating tree
struct Node* createBinaryTree(int key){
    struct Node* binaryTree = (struct Node*)malloc(sizeof(struct Node));
    binaryTree->key=key;
    binaryTree->left=NULL;
    binaryTree->right=NULL;
}

 struct Node* insert(struct Node* rootNode,int key){
     if(rootNode==NULL)
     {
       return createBinaryTree(key);
   }
    if(key < rootNode->key)
        rootNode->left = insert(rootNode->left,key);
    else if(key > rootNode->key)
        rootNode->right = insert(rootNode->right,key);
    
    return rootNode;
}

struct Node* insertNode(struct Node* root, int key) {
    if (root == NULL) {
        return createBinaryTree(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

struct Node* search(struct Node* rootNode,int key){
    if(rootNode==NULL || rootNode->key == key)
        return rootNode;
    
    if(key < rootNode->key){
        search(rootNode->left,key);
    }
    else if(key > rootNode->key){
        search(rootNode->right,key);
    }

}



void inOrder(struct Node* rootNode){
    if(rootNode==NULL)
        return;
    inOrder(rootNode->left);
    printf("%d\t",rootNode->key);
    inOrder(rootNode->right);
}

void main(){
    struct Node* binarySearchTree = createBinaryTree(10);
    binarySearchTree = insert(binarySearchTree,3);
    binarySearchTree = insert(binarySearchTree,7);
    binarySearchTree = insert(binarySearchTree,5);
    binarySearchTree = insert(binarySearchTree,20);
    binarySearchTree = insert(binarySearchTree,12);
    binarySearchTree = insert(binarySearchTree,15);

    inOrder(binarySearchTree);
    int keyToFind = 30; 
    struct Node* result = search(binarySearchTree,keyToFind);
    result!=NULL? printf("Found") : printf("Not Found");
}

