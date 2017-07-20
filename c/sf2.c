#include<stdio.h>
int main()
{
	int ar[105000];
	int i,n,count=0,j;
	scanf("%d",&n);
	for (i = 0; i <105000; i++)
	{
		ar[i]=i;
	}
	for(i=2;i<105000;i++)
	{
		if(ar[i]!=0)
		{
           count++;
           if(ar[j]==n)
           {
           printf("%d\n",count);
           break;
           }
           for(j=2*i;j<105000;j=j+i)
           {
           	  ar[j]=0;
           }
		}
	}
	return 0;
}
