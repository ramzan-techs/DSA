#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>


//Structure of Linked List
struct Node{
    int data;
    struct Node* next;
};

//create new node
struct Node* createNode(int item){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data=item;
    node->next==NULL;
    return node;
}


//Structure of queue
struct Queue{
    struct Node* front;
    struct Node* rear;
    int size;
};

//to create queue
struct Queue* createQueue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front=NULL;
    queue->rear=NULL;
    queue->size=0;
    return queue;
}

//to check if queue is empty
bool isEmpty(struct Queue* queue){
    return queue->front==NULL && (queue->front==queue->rear);
}

//to add item to queue
void enQueue(struct Queue* queue,int item){
    if(isEmpty(queue))
    {
        queue->front = createNode(item);
        queue->size=queue->size+1;
        queue->rear = queue->front;
        return ;
    }
    queue->rear->next = createNode(item);
    queue->rear = queue->rear->next;
    queue->size=queue->size+1;
    
}

//to remove item from queue
int deQueue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Error: Queue is already empty");
        return INT_MIN;
    }
    int removedItem = queue->front->data;
    queue->front=queue->front->next;
    queue->size=queue->size-1;
    return removedItem;
}
//to check first item
int peekFirst(struct Queue* queue){
    if(queue->front==NULL)
        return INT_MIN;
    return queue->front->data;
}

//to check last item
int peekLast(struct Queue* queue){
    if(queue->rear==NULL)
        return INT_MIN;
    return queue->rear->data;
}

void main(){
    struct Queue* queue = createQueue();
    enQueue(queue,20);
    enQueue(queue,30);
    enQueue(queue,40);
    deQueue(queue);
    printf("\n%d is first item\n",peekFirst(queue));
    printf("\n%d is size of queue\n",queue->size);
}