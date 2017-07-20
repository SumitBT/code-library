//find better algorithm for this
#include<iostream>
using namespace std;
int main(void)
{
    int n,j,key,keyi;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int srtd[n][2];
    for(i=0;i<n;i++)
    {
        srtd[i][0]=a[i];
        srtd[i][1]=i;
    }
    for(i=1;i<n;i++)
        {
            key=srtd[i][0];
            keyi=srtd[i][1];
            j=i-1;
            while(j>=0&&key<srtd[j][0])
            {
                srtd[j+1][0]=srtd[j][0];
                srtd[j+1][1]=srtd[j][1];
                j--;
            }
            srtd[j+1][0]=key;
            srtd[j+1][1]=keyi;
         }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
            cout<<srtd[i][j]<<" ";
        cout<<endl;
    }*/
    int c[n];
    for(i=0;i<n;i++)
        c[i]=0;
    for(i=0;i<n;i++)
    {
        c[srtd[i][1]]=0;
    }
    return 0;
}
//Author:SUMITBT
