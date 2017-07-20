//Dynamic Programming
#include<iostream>
using namespace std;
int main(void)
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,sum=0;
        cin>>n;
        int a[n];
        int i,j,key,temp;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(i=1;i<n;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0&&key<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
         }
        int s=1,m=sum;
        for(i=1;i<=n;i++)
        {
            s+=1;
            sum-=a[i-1];
            if(m<s*sum)
                m=s*sum;
        }
        cout<<m<<endl;
    }
    return 0;
}
//Author:SUMITBT
