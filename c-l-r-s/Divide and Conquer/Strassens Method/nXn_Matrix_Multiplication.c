#include<stdio.h>
main()
{
    int m1[5][4]={1,2,2,1,
                  5,3,4,1,
                  7,4,3,4,
                  2,9,0,3,
                  0,6,3,7};
    int m2[4][3]={1,2,3,
                  4,5,6,
                  7,8,9,
                  0,2,6};
    int r[5][3],i,j,k,sum=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            sum=0;
            for(k=0;k<4;k++)
            {
                sum=sum+m1[i][k]*m2[k][j];
            }
            r[i][j]=sum;
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
}
