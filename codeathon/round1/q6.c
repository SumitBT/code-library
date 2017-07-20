#include<stdio.h>
int main()
{
  int x,genroot=0;
  int i ;
  printf("Enter a number for its generic root");
  scanf("%d",&x);
  int a[100];
  for(i=0;i<100;i++)
  {
  a[i]=x%10;
  genroot = genroot + a[i];
  x = x/10;
  if(x==0)
  	break;
  }
  
  printf("genroot is %d",genroot);	
  return 0;
}
