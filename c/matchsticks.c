#include<stdio.h>
int main()
{
    int u,c,sum=0;
    while(1)
    {
    	while(1)
    	{
    		printf("\nenter your input 1/2/3/4\n");
    	    scanf("%d",&u);
    	    if(u<=4&&u>=1)
    	    {
    	    	break;
    	    }
    	    else
    	    {
    	    	printf("enter correct input");
    	    }
    	}
    	sum=sum+u;
    	if(sum>=21)
    	{
    		printf("****..and..Computer..WINS..*****");
    		break;
    	}
    	c=5-u;
    	sum=sum+c;
    	printf("computer input is %d\nmathsticks left=%d",c,21-sum);
    }
	return 0;
}