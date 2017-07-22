#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void fn1(string ,int,int);
void fn2(string ,int,int);
char c[20]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
char v[5]={'a','e','i','o','u'};
int main()
{
    string str="";
    int l=0;
    int n;
    cin>>n;
    for(int i=0;i<20;i++)
    {
        fn1(str+c[i],l+1,n);
    }
    for(int i=0;i<5;i++)
    {
        fn2(str+v[i],l+1,n);
    }
    return 0;
}
void fn1(string str,int l,int n)
{
    if(l==n)
        cout<<str<<endl;
    else
    {
        for(int i=0;i<5;i++)
        {
            fn2(str+v[i],l+1,n);
        }
    }
}
void fn2(string str,int l,int n)
{
    if(l==n)
        cout<<str<<endl;
    else
    {
        for(int i=0;i<20;i++)
        {
            fn2(str+c[i],l+1,n);
        }
    }
}
