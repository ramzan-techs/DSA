#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *Next;
};

void Display(struct Node* Head)
{
    while (Head!=NULL)
    {
        printf("%d",Head->data);
        Head = Head->Next;
    }
    
}
void FindMiddle(struct Node* head){
    struct Node* fast = head;
    struct Node* slow = head;
    while (fast!=NULL && fast->Next!=NULL)
    {
        fast = fast->Next->Next;
        slow = slow->Next;
    }
    printf("%d is the middle element",slow->data);
    
}
int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //memory allocation
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //assigning values
    head->data = 2;
    second->data = 4;
    third->data = 6;



    //linking nodes
    head->Next = second;
    second->Next = third;
    third->Next = NULL;


    Display(head);
    FindMiddle(head);

    //deallocating memory
    head = NULL;
    second = NULL;
    third = NULL;

    return 0;
}