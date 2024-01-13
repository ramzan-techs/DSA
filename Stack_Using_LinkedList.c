#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure of Linked List
struct Node {
    int data;
    struct Node *Next;
};

//Structure of stack
struct Stack{
    struct Node* top;
};

//creating stack
struct Stack* createStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
}

//creating new node of list
struct Node* createNode(int item){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = item;
    node->Next = NULL;
}

//to check stack is empty
bool isEmpty(struct Stack* stack){
    return stack->top==NULL;
}

//to add value to stack
void push(struct Stack* stack,int item){
    struct Node* node = createNode(item);
    node->Next = stack->top; //in this each node will contain reference to previous beacuse of stack implementation 
    stack->top = node; 
}

//to remove value
int pop(struct Stack* stack){
    if(isEmpty(stack))
    {
        printf("Error! Stack is already Empty");
    }
    else{
        struct Node* tempNode = stack->top;
        stack->top = tempNode->Next;
        int data = tempNode->data;
        free(tempNode);
        return data;
    }
}

int peek(struct Stack* stack){
    if(isEmpty(stack))
    {
        printf("Error! Stack is  Empty");
    }
    else{
         return stack->top->data;
    }
   
}



void main(){
    struct Stack* stack = createStack();

    printf("%s",isEmpty(stack)?"true\n":"false\n");

    push(stack,3);
    push(stack,5);
    push(stack,7);
    printf("%d popped\n",pop(stack));
    printf("%d popped\n",pop(stack));
    printf("%s",isEmpty(stack)?"true\n":"false\n");
    printf("%d popped\n",pop(stack));

     printf("%s",isEmpty(stack)?"true\n":"false\n");
}