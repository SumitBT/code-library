#include<iostream>
using namespace std;
int maxprof(int*, int);
int main(void)
{
    int n;
    cout<<"Enter number of Kg's\n";
    cin>>n;
    int a[n];
    cout<<"Enter price list\n";
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Maximum Profit:";
    cout<<"\b="<<maxprof(a,n);
    return 0;
}
int maxprof(int *a,int n)
{
    int i,maxvalue=a[n-1],maxind=n,flag=0;
    for(i=1;i<=n/2;i++)
    {
       if(a[i-1]+a[n-i-1]>=a[n-1])
       {
           maxvalue=a[i-1]+a[n-i-1];
           maxind=i;
           flag=1;
       }
    }
    if(flag==0)
    {
        //cout<<a[n-1]<<"+";
        return a[n-1];
    }
    else if(flag==1)
    {
        return maxprof(a,maxind)+maxprof(a,n-maxind);
    }
}
