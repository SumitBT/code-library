#include<stdio.h>
int main()
{
    int n,i,j,k,l,o=0,c1,c2,c3,count=0,count2=0;
    printf("Enter no. of persons\n");
    scanf("%d",&n);
    int num[n][2],oper[n][n],*ptr,onum[n],sper[n],*ptr2;
    ptr=&oper[0][0];
    ptr2=&sper[0];
    char time[n][9];
        printf("Enter Time period of %d persons in this format : 05AM#12PM \n",n);
        for(i=0;i<=n-1;i++)
        {
           printf("%Time period of person %d\n",i+1);
           scanf("%s",&time[i][0]);
        }
        for(i=0;i<=n-1;i++)
        {
            for(j=0;j<=1;j++)
            {
                if(j==0)
                {
                    c1=2;
                    c2=0;
                    c3=1;
                }
                else
                {
                    c1=7;
                    c2=5;
                    c3=6;
                }
                   if(time[i][c1]=='A')
                   {
                    if(time[i][c3]=='5')
                        num[i][j]=0;
                    if(time[i][c3]=='6')
                        num[i][j]=1;
                    if(time[i][c3]=='7')
                        num[i][j]=2;
                    if(time[i][c3]=='8')
                        num[i][j]=3;
                    if(time[i][c3]=='9')
                        num[i][j]=4;
                    if(time[i][c3]=='0')
                        num[i][j]=5;
                    if(time[i][c3]=='1')
                        num[i][j]=6;
                   }
                   else
                   {
                    if(time[i][c2]=='1'&&time[i][c3]=='2')
                        num[i][j]=7;
                    else if(time[i][c2]=='1'&&time[i][c3]=='0')
                        num[i][j]=17;
                    else if(time[i][c2]=='1'&&time[i][c3]=='1')
                        num[i][j]=18;
                    else if(time[i][c3]=='1')
                        num[i][j]=8;
                    else if(time[i][c3]=='2')
                        num[i][j]=9;
                    else if(time[i][c3]=='3')
                        num[i][j]=10;
                    else if(time[i][c3]=='4')
                        num[i][j]=11;
                    else if(time[i][c3]=='5')
                        num[i][j]=12;
                    else if(time[i][c3]=='6')
                        num[i][j]=13;
                    else if(time[i][c3]=='7')
                        num[i][j]=14;
                    else if(time[i][c3]=='8')
                        num[i][j]=15;
                    else
                        num[i][j]=16;
                   }
                }
            }
            for(i=0;i<=n-1;i++)
            {
                for(j=0;j<=1;j++)
                {
                    printf("%d ",num[i][j]);
                }
                printf("\n");
            }
        return(0);
}
