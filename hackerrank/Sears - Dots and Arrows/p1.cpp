/**
    @author SumitBT ( SumitTamgale@gmail.com )
*/
#include<iostream>
using namespace std;
void solve();
int main(void)
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
        solve();
    return 0;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    bool is;
    for(int i=1;!is;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i%a[j]==0)
                continue;
            else
            {
                is=false;
                break;
            }
        }
        if(is)
        {
            if(k%i==0)
                cout<<"YES\n";
            else cout<<"NO\n";
            break;
        }
    }
}
