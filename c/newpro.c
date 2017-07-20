#include<stdio.h>
int main()
{
	char str[100];
	printf("enter string\n");
	scanf("%s",str);
	int l,i,p,j;
	l=strlen(str);
	for(i=0;i<=l-1;i++)
	{
	   if(str[i]<=57&&str[i]>=48)
	   {
	   	  p=str[i]-48;
	   	  for(j=1;j<=p-1;j++)
	   	  {
	   	  	   printf("%c",str[i+1]);
	   	  }
	   }
	   else
	   printf("%c",str[i]);	
	}
	return 0;
}
