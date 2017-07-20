#include<iostream>
using namespace std;
int main(void)
{
    int n;
    cin>>n;;
    int a[n],i,j,k;
    for(i=0;i<n;i++)
        cin>>a[i];
    int x;
    cin>>x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                for(k=0;k<n;k++)
                {
                    if(j!=k&&k!=i)
                    {
                        if(a[i]+a[j]+a[k]==x)
                        {
                            cout<<"True";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<"False";
    return 0;
}
