/**
    @author SumitBT ( sumittamgale@gmail.com )
    @date 11/05/2017
    */
#include<iostream>
#include<cmath>
using namespace std;
int determinant(int **a, int n);
int main(void)
{
    int n;
    cin>>n;
    int **a,i,j;
    a=new int*[n];
    for(i=0;i<n;i++)
        a[i]=new int[n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    cout<<determinant(a,n);
    return 0;
}
int determinant(int **a, int n)
{
    if(n==2)
    {
        return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    }
    else
    {
        int **temp,i,j,k,sum=0;
        temp=new int*[n-1];
        for(i=0;i<n;i++)
            temp[i]=new int[n-1];
        for(i=0;i<n;i++)
        {
            for(j=1;j<n;j++)
                for(k=0;k<n;k++)
                {
                    if(k<i)
                        temp[j-1][k]=a[j][k];
                    else if(k>i)
                        temp[j-1][k-1]=a[j][k];
                }
            sum+=pow(-1,i+2)*a[0][i]*determinant(temp,n-1);
        }
        return sum;
    }
}
