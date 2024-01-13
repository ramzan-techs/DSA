#include<stdio.h>

//using Recursive function
int Rpow(int m,int n){
    if(n==0)
        return 1;
    return Rpow(m,n-1)*m;
   }

//using recursive but reduced number of multiplication operation
//more efficient then simple recursive

int redPow(int m, int n){
    if(n==0)
        return 1;
    if(n%2==0)
        return redPow(m*m,n/2);
    else
        return m*redPow(m*m,(n-1)/2);
}

//using iterative or loop
int Ipow(int m,int n){
    int res=1;
     for(int i = 1;i<= n ; i++){
        res = res*m;
     }
     return res;
}
//second way same as above
int secIpow(int m,int n){
    int res=m;
     for(int i = 2;i<= n ; i++){
        res = res*m;
     }
     return res;
}

int main(){
    int r;
    //r = Rpow(2,8);
    //r = redPow(2,8);
    //r = Ipow(2,8);
    r = secIpow(2,8);
    printf("%d",r);
}