#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n],b[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int max=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        if(abs(b[i])>abs(b[max]))
        {
            max=i;
        }
    }
    if(b[max]>=0&&a[max]>=0)
    {
        a[max]-=2*k;
    }
    else if(b[max]>=0&&a[max]<0)
    {
        a[max]-=2*k;
    }
    else if(b[max]<0&&a[max]>=0)
    {
        a[max]+=2*k;
    }
    else if(b[max]<0&&a[max]<0)
    {
        a[max]+=2*k;
    }
    long long sum=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i]*b[i];
    }
    printf("%lld",sum);
    return 0;
}
