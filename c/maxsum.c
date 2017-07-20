#include <stdio.h>
void fn();
int main() 
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
        {
        fn();
    }
    return 0;
}
void fn()
    {
    int n;
    scanf("%d",&n);
    int ar[n],i;
    for(i=0;i<=n-1;i++)
        {
        scanf("%d",&ar[i]);
    }
    int maxsum=0,end=0,index=0;
    for (i=0;i<=n-1;i++)
    {
        end=end+ar[i];
        if (end<=0)
        {
            end=0;
            index = i + 1;
        }
        else if (maxsum<end)
        {
            maxsum=end;
        }
   }
    int sum=0;
   for(i=0;i<=n-1;i++)
       {
       if(ar[i]>=0)
           sum=sum+ar[i];
   }
   if(maxsum==0&&sum==0)
   {
    maxsum=ar[0];
    for(i=1;i<=n-1;i++)
    {
        if(ar[i]>maxsum)
            maxsum=ar[i];
    }
    sum=maxsum;
   }
    printf("%d %d\n",maxsum,sum);
}