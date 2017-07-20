#include<stdio.h>
int max_subarray(int*,int,int);
int cross_mid(int*,int,int,int);
main()
{

    printf("%d",max_subarray(a,0,8));
}
int max_subarray(int *a,int low,int high)
{
    if(high==low)
        return a[low];
    else
    {
        int left_sum,right_sum,cross_sum,mid;
        mid=(low+high)/2;
        left_sum=max_subarray(a,low,mid);
        right_sum=max_subarray(a,mid+1,high);
        cross_sum=cross_mid(a,low,mid,high);
        if(left_sum>=right_sum&&left_sum>=cross_sum)
            return left_sum;
        else if(right_sum>=left_sum&&right_sum>=cross_sum)
            return right_sum;
        else return cross_sum;
    }
}
int cross_mid(int *a,int low,int mid,int high)
{
    int left_sum=-1000,right_sum=-1000,sum=0,i;
    for(i=mid;i>=low;i--)
    {
        sum=sum+a[i];
        if(sum>left_sum)
            left_sum=sum;
    }
    sum=0;
    for(i=mid+1;i<=high;i++)
    {
        sum=sum+a[i];
        if(sum>right_sum)
            right_sum=sum;
    }
    return left_sum+right_sum;
}
