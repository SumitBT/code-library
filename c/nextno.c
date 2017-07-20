#include<stdio.h>
int main()
{
	int n,ar[10],i,count=0,temp,order,j,k,l,h;
	printf("Enter No.\n");
	scanf("%d",&n);
	for(i=0;n!=0;i++)
	{
		ar[i]=n%10;
		n=n/10;
		count++;
	}
	/*for(i=count-1;i>=0;i--)
	{
		printf("%d",ar[i]);
	}*/
	for(i=0;i<=count-1;i++)
	{
	    for(j=i;j>=0;j--)
	    {
	    	if(ar[i]<ar[j])
	    	{
	    	  temp=ar[i];
	    	  ar[i]=ar[j];
	    	  ar[j]=temp;
			  for(k=i-1;k>=0;k--)
	             {
		          for(l=k-1;l>=0;l--)
		            {
			          if(ar[k]>ar[l])
			            {
				         h=ar[k];
				         ar[k]=ar[l];
				         ar[l]=h;
			            }
		            }
	             }
			  break;
	    	}
	    }
	}
	for(i=count-1;i>=0;i--)
	{
		printf("%d",ar[i]);
	}
	return 0;
}
