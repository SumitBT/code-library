#include<stdio.h>
void asc(int,int *,int);
int main()
{
	char word[100],*c;
	int i,j,k,ascii[100],count=0,*d,q=0;
	printf("Enter your word in small letters\n");
	scanf("%s",word);
	c=&word[0];
for(i=0;*c!='\0';i++)
	{
		ascii[i]=*c;
		c++;
		count++;
	}
	if(count==1)
    {
	printf("Sorry one letter can only form one word. \n");
    }
	else if(count==2)
	{
		if(ascii[0]<=ascii[1])
		{
			for(i=1;i>=0;i--)
			printf("%c",word[i]);
			printf("\n");
		}
		else
		printf("No word is found after this word in dictionary with these letters. \n");
	}
	else
		{
	     for(i=count-1;i>=0;i--)
	     {
     		if(ascii[i]>ascii[i-1])
     		{
     		    q++;
     			k=ascii[i-1];
     			ascii[i-1]=ascii[i];
     			ascii[i]=k;
     			d=&ascii[i];
     			asc(i,d,count);
     			for(j=0;j<=count-1;j++)
     			{
			     	printf("%c",ascii[j]);
			     }
			     printf("\n");
		     	break;
		     }
     	}
     	if(q==0)
            printf("No word is found after this word in dictionary with these letters. \n");
		}
    return(0);
}
void asc(int x,int *y,int z)
{
	int f,g,h,k=0,temp[z];
	for(f=x;f<=z-1;f++)
	{
		temp[f]=*y;
		y++;
		k++;
	}
	for(f=0;f<=k;f++)
	{
		for(g=f+1;g<=k;g++)
		{
			if(temp[f]>temp[g])
			{
				h=temp[f];
				temp[f]=temp[g];
				temp[g]=h;
			}
		}
	}
	for(f=0;f<=k-1;f++)
	{
		*y=temp[f];
         y++;
	}
}
