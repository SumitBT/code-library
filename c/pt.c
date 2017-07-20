#include<stdio.h>
void main()
{
int i,j,num=1,count=0,n,r,c;
printf("Enter the nummber");
scanf("%d",&n);
for(i=1;num<=n;i++)
{
for(j=1;j<=i;j++)
{
num++;
}
count++;
}
r=count;
c=2*count-1;
int a[r][c];
a[0][r]=1;
num=2;
for(i=1;i<r;i++)
{
for(j=0;j<c;j++)
{
if(j==r-1-i||j==r-1+i)
{
a[i][j]=num;
num++;
}
else
a[i][j]=0;
}
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(a[i][j]!=0)
printf("%d",a[i][j]);
else
printf(" ");
}
}
}
