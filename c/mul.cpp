#include<stdio.h>
int main()
{
    int m1[3][3],m2[3][3],s[3][3],i,j,*ptr,sum=0;
    ptr=&s[0][0];
    printf("Enter elements of matrix 1");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Enter elements of matrix 2");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            sum=sum+m1[i][j]*m2[j][i];
        }
        *ptr=sum;
        ptr++;
        sum=0;
        sum=0;
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf("%d",s[i][j]);
        }
    }
    return(0);
}
