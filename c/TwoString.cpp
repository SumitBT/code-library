#include<stdio.h>
void string();
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		string();
	}
	return 0;
}
void string()
{
	char s1[100],s2[100];
	scanf("%s%s",&s1,&s2);
	int i,j,count=0;
	for(i=0;s1[i]!='\0';i++)
	{
		for(j=0;s2[j]!='\0';j++)
		{
			if(s1[i]==s2[j])
			{
				printf("YES\n");
				count++;
				break;
			}	
		}
		if(count!=0)
			{
				break;
			}
	}
	if(count==0)
	{
		printf("NO\n");
	}
}
