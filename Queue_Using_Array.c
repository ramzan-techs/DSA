#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

//Structure of Queue
struct Queue{
    int front,rear,size;
    unsigned capacity;
    int* arr;
};

//creating queue and allocating memory
struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size=0;
    queue->capacity = capacity;
    queue->rear = queue->capacity-1;
    queue->arr = (int*)malloc(capacity*sizeof(int));
}

//to check if queue is full
bool isFull(struct Queue* queue){
    return queue->size==queue->capacity;
}

//to add item in queue
void enQueue(struct Queue* queue,int item){
    if(isFull(queue))
    {
        printf("\nQueue is Full!\n");
        return;
    }
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear]=item;
    queue->size= queue->size+1;
}


//to check if queue is empty
bool isEmpty(struct Queue* queue){
    return queue->size==0;
}

//to remove item from queue
int deQueue(struct Queue* queue){
    if(isEmpty(queue))
    {
        printf("Queue is already Empty!");
        return INT_MIN;
    }
    int itemRemoved = queue->arr[queue->front];
    queue->front = (queue->front +1)%queue->capacity;
    queue->size = queue->size-1;
    return itemRemoved;
}

//to check first item
int queueFirstItem(struct Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

//to check last item
int queueLastItem(struct Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}


void main(){
    struct Queue* queue = createQueue(10);
    enQueue(queue,30);
    enQueue(queue,40);
    enQueue(queue,50);

    printf("\n%d is Popped from queue\n",deQueue(queue));

    printf("\n%d is first element\n",queueFirstItem(queue));
    printf("\n%d is Last element\n",queueLastItem(queue));
    
}