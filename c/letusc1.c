#include<stdio.h>
int main()
{
int i,m,sum=0;
for(i=1;i<=5;i++)
{
scanf("%d",&m);
sum=sum+m;
}
printf("aggregate=%d pecentage=%d%",sum,sum/5);
return 0;
}
