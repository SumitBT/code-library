#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int sum1=a+d+e;
	int sum2=a+b+c+d;
	int sum3=a+b+f;
	int min=sum1;
	if(sum1>=0&&sum2>=0&&sum3>=0)
		printf("-1");
	else
	{
      if(sum2<min)
      	min=sum2;
      if(sum3<min)
      	min=sum3;
      printf("%d",-1*min);
	}
	return 0;
}