#include<stdio.h>
int main()
{
	int i,j,k=65,l,m=0,n;
	int ar[7][13];
	for(i=0;i<=6;i++)
	{
		 k=64;
	   for(j=0;j<=12;j++)
	   {
	   	 
	   	 if(j<=6)
	   	 k++;
	   	 else
	   	 k--;
	   	 ar[i][j]=k;
       }
       if(i!=0)
       {
       	l=6;
           for(n=l-m;n<=l+m;n++)
            {
       	       ar[i][n]=' '; 
            }
            m++;
       }
	}
	for(i=0;i<=6;i++)
	{
		for(j=0;j<=12;j++)
		{
			printf("%c ",ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}
