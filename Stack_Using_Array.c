#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
//Structure of stack
struct Stack {
    int top;
    unsigned size;
    int* arr;
};

//creating stack and memory allocation

struct Stack* create(unsigned size){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = size;
    stack->arr = (int*)malloc(stack->size*sizeof(int));
}

//to check if stack is full

bool isFull(struct Stack* stack){
    return stack->top == stack->size-1;
}

//to check if stack is empty

bool isEmpty(struct Stack* stack){
    return stack->top == -1;
}

//to add elements in stack 
int push(struct Stack* stack,int item){
    if(isFull(stack))
        return 1;
    stack->arr[++stack->top]=item;
    return 0;   
}

//to remove elements in stack
int pop(struct Stack* stack){
    if(isEmpty(stack))
    {   printf("Error: Stack is alredy empty"); 
        return -1;
    }
    return stack->arr[stack->top--];
}

//to get top element
int peek(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}

int main(){
    struct Stack* stack = create(10);
    push(stack,10);
    // push(stack,20);
    // push(stack,30);

    printf("%d pooped!",pop(stack));
    printf("%d pooped!",pop(stack));
    isEmpty(stack)? printf("Stack is empty"):printf("Stack is not empty");
}