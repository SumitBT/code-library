#include<stdio.h>

int main()

{

  int ar[10],i,j,c,temp;

  int ar2[10],d[10];

  printf("enter 10 nos");

  for(i=0;i<=9;i++)

  {

   scanf("%d",&ar[i]);

  }

  for(i=0;i<=9;i++)

  {

  for(j=0;j<=7;j++)

  {

  if(ar[i]>ar[i+1])

  {

  temp=ar[i];

  ar[i]=ar[i+1];

  ar[i+1]=ar[i];

  }

  }

  }

  for(i=0;i<=9;i++)

  {

  printf("%d ",ar[i]);

  }

   for(i=0;i<=9;i++)
   {
    for(j=0;j<=9;j++)
   {
    if(i!=j)
    {
       if(a[i]==a[j])
        continue;
        else
           printf("%d",a[i]);
    }
   return 0;

}
