#include<iostream>
using namespace std;
int main(void)
{
    int n,i,j;
    cin>>n;
    int s=(2*n)+1;
    char **a = new char*[s];
    for(i=0;i<s;i++)
        a[i]=new char[s];
    for(i=0;i<s;i++)
    {
        for(j=0;j<s;j++)
        {
            a[i][j]=' ';
        }
    }
    for(i=s;i>=3;i=i-2)
    {
        for(j=0;j<i;j++)
        {
            a[0][j]='*';
        }
        for(j=0;j<i;j++)
        {
            a[j][i-1]='*';
        }
        for(j=0;j<i;j++)
        {
            a[i-1][j]='*';
        }
        for(j=0;j<i;j++)
        {
            a[j][0]='*';
        }
    }
    for(i=0;i<s;i++)
    {
        for(j=0;j<s;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    for(i=0;i<s;i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
