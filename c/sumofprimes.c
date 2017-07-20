#include<stdio.h>
int main()
{
	int i,t,n,j,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		long unsigned int sum=0;
		scanf("%d",&n);
		int ar[n+1];
		for(j=0;j<=n;j++)
		{
			ar[j]=0;
		}
		for(j=2;j<=n;j++)
		{
			if(ar[j]==0)
			{
				ar[j]=j;
				for(k=2*j;k<=n;k=k+j)
					ar[k]=1;
			}
		}
		for(j=2;j<=n;j++)
		{
			if(ar[j]!=1)
			{
			sum=sum+ar[j];
		    }
		}
		printf("%lu\n",sum);
	}
	return 0;
}
