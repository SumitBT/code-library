#include<stdio.h>
int main()
{
int x = 2323;
int y;
int a[2];
a[0]=x%10;
x = x/10;
a[1]=x%10;
x = x/10;
y = x*100 + (a[0]*10) + (a[1]);
printf("%d",y);
  
  return 0;
}
