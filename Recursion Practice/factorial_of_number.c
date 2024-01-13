#include<stdio.h>

//using iterative or loop
int Ifact(int n){
    int i,fact=1;
    for(i=1;i<=n;i++){
        fact = fact * i;
    }
    return fact;
}

//using recursive function
int Rfact(int n){
    if(n==0)
        return 1;
    else
        return Rfact(n-1)*n;
}


int main(){
    int fact;
    //fact = Ifact(5);
    fact = Rfact(5);
    printf("%d",fact);
    return 0;
}