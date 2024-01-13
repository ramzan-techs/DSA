#include<stdio.h>

double e(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else
    {
        r = e(x,n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }
}

//using horner's rule for less no of multiplications
double horner_e(int x,int n){
    static double s=1;
    if(n==0)
        return s;
    s = 1 + ((double)x/(double)n)*s;
    return horner_e(x,n-1);
}

//using loop for horner's rule
double loop_horner_e(int x,int n){
    double s = 1;
    for(;n>0;n--){
        s = 1 + (double)x/(double)n*s;
    }
    return s;
}

int main()
{
    printf("%lf\n", e(1,15));  //lf => long float means double
    printf("%lf\n",horner_e(1,10));
    printf("%lf",loop_horner_e(1,10));
}