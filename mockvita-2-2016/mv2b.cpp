#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(void)
{
    float m,t;
    float r;
    cin>>m>>t>>r;
    int x=((m*t)+((t*(t-1)*5*r)/24))/(1+((t*r)/1200));
    cout<<x;
    return 0;
}
