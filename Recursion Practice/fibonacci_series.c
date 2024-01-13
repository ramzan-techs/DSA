#include<stdio.h>

//using loop

int loop_fib(int n){
    int t_0 = 0, t_1 = 1, s;
    if(n<=1)
        return n;
    for(int i =2; i<=n;i++){
        s = t_0 + t_1;
        t_0 = t_1;
        t_1 = s;
    }

    return s;
}

//using simple recursion => Excessive recursion recursive call made many times for same value
int rec_fib(int n){
    if(n<=1)
        return n;
    return rec_fib(n-2) + rec_fib(n-1);
}

//Memoization => storing result of each call in static or global so that when call is made for same value again stored value used

int memoization_fib(int n){
    static int F[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //we can also use global array 
    if(n<=1)
    {   F[n] = n;
        return n;
    } 
    else
    {
        if(F[n-2]==-1)
            F[n-2] = memoization_fib(n-2);
        if(F[n-1]==-1)
            F[n-1] = memoization_fib(n-1);

        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}



int main(){
    printf("%d\n",loop_fib(8));
    printf("%d\n", rec_fib(8));
    printf("%d\n",memoization_fib(8));
}