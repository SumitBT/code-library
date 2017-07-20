#include<iostream>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    char a[n][n+1];
    int i,j;
    for(i=0;i<n;i++)
        cin>>a[i];
    /*for(i=0;i<n;i++)
        cout<<a[i]<<endl;*/
    int pi,pj,qi,qj;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]=='P')
            {
                pi=i;
                pj=j;
            }
            if(a[i][j]=='Q')
            {
                qi=i;
                qj=j;
            }
        }
    }
    int d=(qi>pi?qi-pi:pi-qi)+(qj>pj?qj-pj:pj-qj);
    cout<<d;
    return 0;
}
