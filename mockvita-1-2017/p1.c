#include <stdio.h>
int main()
{
    int n,i,j,l=0;
    scanf("%d",&n);
    int k=n*(n+1)/2;
    int a[k];
    a[0]=6;
    for(i=1;i<k;i++)
    {
        a[i]=a[i-1]+(6+16*(i));
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%05d ",a[l++]);
        }
        printf("\n");
    }
    return 0;
}
