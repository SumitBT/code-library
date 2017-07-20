#include<stdio.h>
int main()
{
  int n,i;
  printf("enter number");
  scanf("%d",&n);
  for(i=0;i<=n;i++)
  {
   if((i*i)==n)
   {
   printf("%d",i);
   break;
   }
  }
  return 0;
}
