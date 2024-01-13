#include<stdio.h>

//formula for factorial

int fact(int n){
    if(n==0)
        return 1;
    return fact(n-1)*n;
}

//direct formula function of nCr
// nCr = n!/(r!(n-r)!)
int nCr(int n,int r)
{
    int numerator,denominator;
    numerator = fact(n);
    denominator = fact(r)*fact(n-r);

    return numerator/denominator;
}

//using recursion by implementing Pascal's Triangle

int rec_nCr(int n,int r)
{
    if(n==r || r==0)
        return 1;
    return rec_nCr(n-1,r-1) + rec_nCr(n-1,r);
}

int main(){
    printf("%d\n",nCr(4,2));
    printf("%d\n",rec_nCr(4,2));
}