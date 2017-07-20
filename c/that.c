#include<stdio.h>
void main()
{
int i,j,k,l,sp;
sp=10;
for(i=1,k=1;i<5;i++)
{
for(l=1;l<=sp;l++)
printf(" ");
sp--;
for(j=1;j<=i;j++,k++)
printf("%d ",k);
printf("\n");
}
}