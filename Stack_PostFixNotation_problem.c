#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<ctype.h>
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
        return -1;
    return stack->arr[stack->top--];
}

//to get top element
int peek(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}

bool isOperator(char c){
    return (c == '+' || c=='*' || c=='/' || c=='-');
}
int performOperation(int Num1,int Num2,char operator){
    switch (operator)
    {
    case '+':
        return Num1 + Num2;
        break;
    case '*':
        return Num1 * Num2;
        break;   
    case '-':
        return Num1 - Num2;
    case '/':
        return (int)(Num1/Num2);
        break;
    default:
        break;
    }
}

int main(){
    char arr[] = {'6','8','2','1','+','-','*'};
    int Num1;
    int Num2;
    int finalResult;
    struct Stack* stack = create(10);
    for (int i =0;i<7;i++){
        if(isOperator(arr[i]))
        {
            Num2 = pop(stack);
            Num1 = pop(stack);
            push(stack,performOperation(Num1,Num2,arr[i]));
        }
        else
        {   
            push(stack,(int)(arr[i]-'0')); //to convert char digit  into integer digit minus '0' from it 
        }
    }

    finalResult = peek(stack);
    printf("%d",finalResult);
    
}