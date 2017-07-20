#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(void)
{
    double x,y,dx,dy;
    cin>>x>>y>>dx>>dy;
    double mind=x+y,d;
    if(x/dx==y/dy)
        printf("%.1f",0.0);
    else if(x/dx<y/dy)
    {
        mind=y-(dy*x/dx);
        if(dy>dx)
        {
            mind=abs(x-(dx*y/dy));
            cout<<mind;
        }
    }
    else if(x/dx>y/dy)
    {
        mind=x-(dx*y/dy);
        if(dy>dx)
        {
            mind=abs(y-(dy*x/dx));
            cout<<mind;
        }
    }
    return 0;
}
