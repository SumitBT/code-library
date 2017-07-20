#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,m,i,j,k,l=0,r=0,u=0,d=0;
    scanf("%d%d",&n,&m);
    char str[n][m];
    int ar[n][m];
    for(i=0;i<=n-1;i++)
        {
            scanf("%s",&str[i][0]);
    }
    for(i=0;i<=n-1;i++)
        {
            printf("%s\n",&str[i][0]);
        //printf("\n");
    }/*
    for(i=0;i<=n-1;i++)
        {
        for(j=0;j<=m-1;j++)
            {
            if(str[i][j]=='B') 
            {
                ar[i][j]=0;
            }
            if(str[i][j]=='G')
                {
                for(k=j;k>=0;k--)
                    {
                    if(str[i][k]=='G')
                        l++;
                    if(str[i][k]=='B')
                        break;
                }
                for(k=j;k<=m-1;k++)
                    {
                    if(str[i][k]=='G')
                        r++;
                    if(str[i][k]=='B')
                        break;
                }
                for(k=i;k>=0;k--)
                    {
                    if(str[k][j]=='G')
                        u++;
                    if(str[k][j]=='B')
                        break;
                }
                for(k=i;k<=m-1;k++)
                    {
                    if(str[k][j]=='G')
                        d++;
                    if(str[k][j]=='B')
                        break;
                }
            if(l==r&&r==u&&u==d)
                {
                ar[i][j]=(4*l)+1;
                l=0;r=0;u=0;d=0;
            }
            else
                {
                ar[i][j]=1;
                l=0;r=0;u=0;d=0;
            }
            }
        }
    }
    for(i=0;i<=n-1;i++)
        {
        for(j=0;j<=m-1;j++)
            {
            printf("%d",ar[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}