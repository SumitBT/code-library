#include<stdio.h>
int main()
{
int n,k,q,i,j,f,l;
scanf("%d%d%d",&n,&k,&q);
int ar[n];
for(i=0;i<=n-1;i++)
    scanf("%d",&ar[i]);
int temp[n];
for(l=1;l<=k;l++)
{
    for(i=0;i<=n-1;i++)
        temp[i]=ar[i];
    for(j=0;j<=n-1;j++)
    {
        if(j==0)
            ar[j]=temp[n-1];
        else
            ar[j]=temp[j-1];
    }
}
for(i=1;i<=q;i++)
{
    scanf("%d",&f);
    printf("%d\n",ar[f]);
}
return 0;
}
