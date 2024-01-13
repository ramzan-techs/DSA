#include<stdio.h>

void main(){
    int arr[] = {1,2,3,2,3,4,5,1,5};
    int res = 0;
    for(int i = 0;i<9;i++)
    {
        res = res ^ arr[i];
    }
    printf("Single element is %d", res);
}