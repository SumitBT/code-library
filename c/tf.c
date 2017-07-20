#include<stdio.h>
int main()
{
	int i,j,k;
	int ar[]={2,8,5,6,3,9,2};
	for(i=1;i<=6;i++)
	{
		for(j=0;j<=5;j++)
		{
			if(ar[j]>ar[j+1])
			{
				k=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=k;
			}
		}
	}
	for(i=0;i<=6;i++)
	{
		printf("%d",ar[i]);
	}
	return 0;
}
