#include<stdio.h>
int ar[100000001];
int main()
{
	int i,t,n,j,l,k;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int count=0;
		scanf("%d",&n);
		for(j=2;j<=100000000;j++)
	    {
		   if(ar[j]==0)
		   {
		     ar[j]=j;
			 for(k=2*j;k<=100000000;k=k+j)
			    {
			     	ar[k]=1;
			    }
		   }
	    }
	    for(l=2;i<=100000000;l++)
	    {

	    	if(ar[l]!=1)
	    	count++;
	    	if(count==n)
	    	break;
	    }
	    printf("%d\n",ar[l]);
	}
	return 0;
}
