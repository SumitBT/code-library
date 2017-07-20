#include<iostream>
using namespace std;
int max_prof(int*, int);
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
    cout<<"Maximum Profit: "<<max_prof(a,n);
    return 0;
}
int max_prof(int *a,int n)
{
    int i,max_value=a[n-1],max_ind=n,flag=0;
    for(i=1;i<=n/2;i++)
    {
       if(a[i-1]+a[n-i-1]>=a[n-1])
       {
           max_value=a[i-1]+a[n-i-1];
           max_ind=i;
           flag=1;
       }
    }
    if(flag==0)
    {
        return a[n-1];
    }
    else if(flag==1)
    {
        return max_prof(a,max_ind)+max_prof(a,n-max_ind);
    }
}
