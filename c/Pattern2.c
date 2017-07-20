#include<stdio.h>
void main()
{
int i,n=1,sp=18,j,k,l=1,m;
        for(m=1;m<=20;m++)
        {
            printf(" ");
        }
        printf("1\n");
        for(i=1;i<10;i++,l++)
        {
            for(j=1;j<=sp;j++)
            {
                printf(" ");
            }
            sp=sp-2;
            for(k=1;k<=l;k++)
            {
             printf("%d ",n);
            n=2*n;
            }
            while(n>=1)
            {
            printf("%d ",n);
            n=n/2;
            }
            n=1;
            printf("\n");
        }
}