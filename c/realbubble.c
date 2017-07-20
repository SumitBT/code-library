#include<stdio.h>
int main()
{
	int i,j,k;
	int ar[]={2,8,5,6,-3,9,2,0,0,3,4,5,6,4,-3,5,6,3,43,4,5,5,34,3,5,54,4,44,5};
	for(i=1;i<=28;i++)
	{
		for(j=0;j<=27;j++)
		{
			if(ar[j]<ar[j+1])
			{
				k=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=k;
			}
		}
	}
	for(i=0;i<=28;i++)
	{
		printf("%d ",ar[i]);
	}
	return 0;
}
