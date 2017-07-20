#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,a[50000];
	for(i=0;i<50000;i++)
		scanf("%d",&a[i]);
	FILE *fp;
	fp = fopen("primes.txt", "w");
	for(i=0;i<15000;i++)
	{
		fprintf(fp,"%d",a[i]);
		fprintf(fp,",");
	}	
	//printf("%d",sizeof(a));
	return 0;
}