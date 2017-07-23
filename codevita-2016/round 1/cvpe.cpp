#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
    bool found=false;
    int i,j,n,T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
    cin>>n;
    long long sum=0,num=0,c=0;
    for(i=1;found==false;i++)
        for(j=0;j<i;j++)
        {
            num=pow(2,i)+pow(2,j);
            if(c<n)
            {
                sum+=num;
                c++;
            }
            else
            {
                found=true;
                break;
            }
        }
        cout<<sum%1000000007;
        found=false;
    }

    return 0;
}
