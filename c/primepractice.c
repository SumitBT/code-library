#include<stdio.h>
int main()
{
	int ar[200],i,k;
	for(i=0;i<=199;i++)
	{
		ar[i]=i+1;
	}
	for(i=0;i<=199;i++)
	{
		if(ar[i]!=0)
		{
			k=i;
			while(k<=199)
			{
				k=k+i;
                ar[k]=0;
			}
		}
	} 
	for(i=0;i<=199;i++)
	{
		if(ar[i]!=0)
		{
			printf("%d\n",ar[i]);
		}
	}
	return 0;
}
