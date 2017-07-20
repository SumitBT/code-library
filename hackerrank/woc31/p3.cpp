#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int g;
    cin>>g;
    int n,count,i,j;
    for(int k=1;k<=g;k++)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        count=0;
        bool flag;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                flag=false;
                for(j=i+1;j<n-1;j++)
                {
                    if(a[j]!=0&&a[j+1]!=0)
                        {
                        if(flag)
                            count--;
                        i=j+2;
                        break;
                    }
                    else
                        {
                        flag=true;
                        count++;
                    }
                }
            }
        }
        cout<<count;
        if(count%2==0)
            cout<<"Bob\n";
        else cout<<"Alice\n";
    }
    return 0;
}
