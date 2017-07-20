//using divide-and-conquer method
#include<iostream>
using namespace std;
int max_points(int*,int,int,int);
int main(void)
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        int a[n];
        int i,sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        cout<<max_points(a,0,n-1,sum)<<endl;
    }
    return 0;
}
int max_points(int *a,int p,int r,int sum)
{
    if(r-p>=1)
    {
        int left_sum=0,i,l,rm;
        bool found=0;
        for(i=p;i<r;i++)
        {
            left_sum+=a[i];
            sum-=a[i];
            if(sum==left_sum)
            {
                l=max_points(a,p,i,left_sum);
                rm=max_points(a,i+1,r,sum);
                found=1;
                if(l>rm)
                    return 1+l;
                else return 1+rm;
            }
        }
        if(found==0)
            return 0;
    }
    else return 0;
}
// Time Complexity : O(n log(n))
// Author : SUMITBT
