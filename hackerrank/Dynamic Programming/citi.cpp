#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
        cin>>n>>k;
        int a[n];
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];

        }
    i=0;
    int j,count=0;
    bool got=0;
    while(i<n)
        {
        if(a[i]==0)
            {
            for(j=i+1;j<=i+k;j++)
                {
                if(j<n)
                    {
                     if(a[j]==1)
                    {
                    i=j+k+1;
                    count++;
                    got=1;
                    break;
                }
                }

            }
            if(got==0)
                {
                for(j=i-1;j>=i+k;j--)
                {
                if(j>=0)
                    {
                    if(a[j]==1)
                    {
                    i=j+k+1;
                    count++;
                    got=1;
                    break;
                }
                }

            }
            }

            if(got==0)
                {
                cout<<-1;
                break;
            }
        }
    }
    cout<<count;
    return 0;
}
