#include<stdio.h>
int main()
{
    int ar[1][2]={1,2},i;
    for(i=1;i<=9;i++)
    {
       int* ar[2][0]=(int* ar[][])malloc(2*sizeof(int));
       ar[i][0]=1;
       ar[i][1]=2;
    }
	return 0;
}