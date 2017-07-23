#include<iostream>
using namespace std;
int main(void)
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        long long n,m;
        cin>>n>>m;
        if(n==m)
            cout<<1<<" ";
        else
        {
            if(n>m)
            {
                if(n>2*m)
                    cout<<-1<<" ";
                else cout<<n-m<<" ";
            }
            if(n<m)
            {
                if(m>2*n)
                    cout<<-1<<" ";
                else cout<<m-n<<" ";
            }
        }
    }
    return 0;
}
