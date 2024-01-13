#include<stdio.h>

double self_sin(double x, int n)
{
    static double p=1,f=1,r,currentFact=1;
    static int isAdd=0;
    if(n==1)
    {   p = x;
        return x;
    }
    else
    {
        r = self_sin(x,n-1);
        p = p*x*x;
        currentFact = currentFact*(f+1)*(f+2);
        f = f + 2;
        if(isAdd==1)
        {
            isAdd = 0;
            return r + (p/currentFact);
        }
        else
        {
            isAdd = 1;
            return r - (p/currentFact);
        }
    }
}


int main(){
    printf("%lf",self_sin(2,10));
}

