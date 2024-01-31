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
    if(arr->length == arr->size && index > arr->length){
         return -1;
    }
    else{
    for(int i = arr->length;i>=index;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = value;
    //arr.A[arr.length] = arr.A[arr.length - 1];
    arr->length++;
    return value;
    }
}

//add element at end function will return index at whichh value is added
int add(struct Array *arr,int value){
    if(arr->length == arr->size)
    {
        return -1;
    }
    else{
    arr->A[arr->length] = value;
    arr->length++;
    return arr->length-1;
    }
}

//delete element at specific index
int delete(struct Array *arr,int index)
{
    if(index>=0 && index < arr->length)
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

//linear searching
// will return index if key is found
//using call by value because original values will remain same
int linearSearch(struct Array arr,int key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key == arr.A[i])
            return i;
    }

    return -1;
}

//swap method for swapping two valus in array
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

}

//linear search with improvemnt
//1-Transposition  --> we replace searched value if found with previous value
//2-Move to head/front  --> we replace searched value if found with the first value in array


//1-transposition
int linearSearchWithTransposition(struct Array *arr,int key)
{
    for(int i = 0; i<arr->length;i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i-1],&arr->A[i]);
            return i;
        }
    }

    return -1;
}
//2-Move to head
int linearSearchMoveToHead(struct Array *arr,int key){
    for(int i=0;i<arr->length;i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[0],&arr->A[i]);
            return i;
        }
    }
    return -1;
}

//Binary Search checking middle element and if not then dividing list in half according to mid
//array should be sorted , which half should be used second time depends if key greater or less then mid

int binarySearch(struct Array arr,int key)
{
    int l = 0,h = arr.length-1;
    int mid;

    while(l<=h)
    {
        mid =  (l + h)/2;
        if(arr.A[mid]==key)
           return mid;
        else if(key>arr.A[mid])
           l = mid + 1; 
        else
           h = mid - 1;
     }
    return -1;
}

//Recursive binary search
int RBinarySearch(int a[],int l,int h,int key)
{
    int mid = (l+h)/2;
    if(l<=h){
    if(key == a[mid])
        return mid;
    else if(key > a[mid])
        RBinarySearch(a,mid + 1,h,key);
    else
        RBinarySearch(a,l,mid - 1,key);
    }

    return -1;
    
}

//for getting value at specific location
int get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
}

//for changing value at specific index
void set(struct Array *arr,int index,int value)
{
    if(index>=0 && index<arr->length)
         arr->A[index] = value;
}

//for getting max value 
int max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 0;i<arr.length;i++)
        if(max<arr.A[i])
            max = arr.A[i];

    return max;
}

//for getting min value 
int min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 0;i<arr.length;i++)
        if(min>arr.A[i])
            min = arr.A[i];

    return min;
}

//for getting total sum of all values 
int sum(struct Array arr)
{
    int totalSum = 0;
    for(int i = 0;i<arr.length;i++)
        totalSum = totalSum + arr.A[i];

    return totalSum;
}

//recursive sum finding
int recursiveSum(int a[],int n)
{
    if(n<0) //base condition
        return 0;
    else
        return a[n] + recursiveSum(a,n-1); 
}

//for finding avg of all values in array
float average(struct Array arr)
{
    int totalSum = 0;
    for(int i = 0;i<arr.length;i++)
        totalSum = totalSum + arr.A[i];

    return ((float)totalSum)/((float)arr.length);
}

//reversing of array
//1-auxilaryReversing using extra array
//2-simple reversing without extra array

//1-auxilary reversing
void auxilaryReverse(struct Array *arr)
{   
    int *B;  //extra array
    //allocating memory in heap
    B = (int *)malloc(arr->length*sizeof(int));
    int i,j; //i->will point to last index of original array and will be decrementing
    //j-> will point to first index of second array and incrementing
    for(i = arr->length-1,j=0;i>=0;i--,j++)
        B[j] = arr->A[i]; //storing element in extra array in reverse order

    for(i = 0;i<arr->length;i++)
        arr->A[i] = B[i];

    free(&B);
}

//2- simple reverse 
void reverse(struct Array *arr)
{
    int i,j;
    //i-> will point index incrementing from start
    //j-> will point index decrementing from last

    for(i=0,j=arr->length-1;i<j;i++,j--)
        swap(&arr->A[i],&arr->A[j]);
    
}

// to shift array one value right 
void rightShift(struct Array *arr)
{   if(arr->length == arr->size)
       { for(int i=arr->length-1; i>0; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[0] = 0;
       }
    else
       { for(int i=arr->length; i>0; i--)
        {
             arr->A[i] = arr->A[i-1];
        }
        arr->A[0] = 0;
        arr->length = arr->length + 1;
       }
}

// to shift array one value left
void leftShift(struct Array *arr)
{
    for(int i = 0; i < arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
}

// to left rotate array
void leftRotate(struct Array *arr)
{
    int temp = arr->A[0];
    for(int i = 0; i < arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}

// to right rotate array
void rightRotate(struct Array *arr)
{
    int temp = arr->A[arr->length-1];
    for(int i = arr->length - 1; i>0 ; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}


//for releasing memory to avoid memory leakage
void releaseArray(struct Array *arr) {
    free(arr->A);
    arr->A = NULL; // Optional: Set the pointer to NULL after freeing to avoid dangling pointers
    arr->size = 0;
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

    //insert(&arr,2,10);

    //printf("\nElement is stored at  %d index", linearSearch(arr,7));

   // printf("\nElement is found at %d\n",linearSearchWithTransposition(&arr,10));

   // printf("\nElement is found at %d",linearSearchMoveToHead(&arr,4));

    //printf("\n Element is found at %d using binary search",binarySearch(arr,3));

    // printf("\n Element is found at %d using binary search",RBinarySearch(arr.A,0,5,3));

    // printf("%d is the max value\n",max(arr));
    //  printf("%d is the min value\n",min(arr));
    //   printf("%f is the average value\n",average(arr));
    //  printf("%d is the sum of values\n",sum(arr));
    //   printf("%d is the recursive sum value\n",recursiveSum(arr.A,arr.length -1));



    //auxilaryReverse(&arr);
    // reverse(&arr);
       

    // rightShift(&arr);

    // leftShift(&arr);

    // leftRotate(&arr);

    rightRotate(&arr);



    printf("\nElements are : ");
   // add(&arr,20);
   // delete(&arr,1);
    Display(&arr);

    releaseArray(&arr);
}
