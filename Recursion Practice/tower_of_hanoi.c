#include<stdio.h>

//recursive function

void TOH(int n,char diskA,char diskB,char diskC)
{
    if(n>0)
    {
        TOH(n-1,diskA,diskC,diskB);
        printf("Move from %c to %c \n", diskA,diskC);
        TOH(n-1,diskB,diskA,diskC);
    }    
}

int main(){
    TOH(8,'A','B','C');

    return 0;
}