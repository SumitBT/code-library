#include<stdio.h>
int main()
{
	int ar[105000];
	int i,n,count=0,j,t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
	scanf("%d",&n);
	for (i = 0; i <105000; i++)
	{
		ar[i]=i;
	}
	for(i=2;count<n;i++)
	{
		if(ar[i]!=0)
		{
           count++;
           if(count==n)
           {
           printf("%d\n",ar[i]);
           break;
           }
           for(j=2*i;j<105000;j=j+i)
           {
           	  ar[j]=0;
           }
		}
	}
	count=0;
    }
	return 0;
}
