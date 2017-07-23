#include<stdio.h>

int add(int, int);

int main()

{

  int a,b,c;

  printf("Enter two nos");

  scanf("%d%d",&a,&b);

  c=add(a,b);

  printf("%d",c);

  return 0;

}


int add(int num1,int num2)

{

	if(!num1)

	return num2;

	else

   	return(add((num1 & num2)<<1,(num1 ^ num2)));

}
