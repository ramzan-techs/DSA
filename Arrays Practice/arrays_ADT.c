#include<stdio.h>
#include<stdlib.h>

struct Array
{   
    int *A;
    int size;
    int length;
    };
//for displaying stored elements
void Display(struct Array *arr)
{
    for(int i = 0;i<arr->length;i++){
        printf("%d ",arr->A[i]);
    }
}

//inserting element in array
int insert(struct Array *arr,int index,int value)
{
    if(arr->length == arr->size){
        printf("\nArray is Full\n");
        return -1;
    }
    for(int i = arr->length;i>=index;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = value;
    //arr.A[arr.length] = arr.A[arr.length - 1];
    arr->length++;
    return value;
}

//add element at end function will return index at whichh value is added
int add(struct Array *arr,int value){
    if(arr->length == arr->size)
    {
        printf("\nArray is Full\n");
        return -1;
    }
    arr->A[arr->length] = value;
    arr->length++;
    return arr->length-1;
}

//delete element at specific index
int delete(struct Array *arr,int index)
{
    if(index>0 && index < arr->length)
    {   int deletedValue = arr->A[index];
        for(int i = index;i<arr->length-1;i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return deletedValue;
    }
    return -1;
}
void main(){
    struct Array arr;
    int n,i;
    printf("Enter size of Array: ");
    scanf("%d",&arr.size);

    //creating array in heap
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0;

    //asking no of elements to be store 
    printf("\nEnter number of elements to be stored: ");
    scanf("%d",&n);

    //getting elements
    printf("\nEnter elements\n");
    for(i = 0;i<n;i++)
            scanf("%d",&arr.A[i]);
    arr.length=n;

    insert(&arr,2,10);

    printf("\nElements are : ");
    add(&arr,20);
    delete(&arr,1);
    Display(&arr);
}
