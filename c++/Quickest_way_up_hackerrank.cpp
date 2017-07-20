#include<iostream>
using namespace std;
int graph[100][6];
void answer();
void create(int);
int main(void)
{
    int T,t;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        answer();
    }
    return 0;
}
void answer()
{
    int i,j,k,l,m;
    for(i=0;i<=99;i++)
    {
        graph[i][0]=-1;
    }
    cin>>j;
    for(i=1;i<=j;i++)
    {
        cin>>k;
        cin>>l;
        for(m=0;m<=5;m++)
        {
            if(graph[k-1][m]==-1)
            {
                graph[k-1][m]=l-1;
                graph[k-1][m+1]=-1;
                break;
            }
        }
    }
    cin>>j;
    for(i=1;i<=j;i++)
    {
        cin>>k;
        cin>>l;
        for(m=0;m<=5;m++)
        {
            if(graph[k-1][m]==-1)
            {
                graph[k-1][m]=l-1;
                graph[k-1][m+1]=-1;
                break;
            }
        }
    }
    create(0);
    /*for(i=0;i<=99;i++)
    {
        cout<<i+1;
        for(j=0;j<=5;j++)
        {
            if(graph[i][j]==-1)
            {
                break;
            }
            else cout<<" "<<graph[i][j]+1;
        }
        cout<<endl;
    }*/
}
void create(int n)
{
    int i,j,k;
    for(i=n;i<=n+6;i++)
    {
        if()
    }
}
