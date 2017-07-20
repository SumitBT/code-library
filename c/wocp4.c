#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int ar[n];
    int i,ans=0;
    for(i=0;i<=n-1;i++)
    {
    	scanf("%d",&ar[i]);
    }
    //printf("%d",6%1000000007);
    for(i=1;i<=n;i++)
    {
    	ans=ans+i;
    }
    printf("%d",ans);
	return 0;
}