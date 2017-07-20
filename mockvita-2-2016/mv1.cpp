#include<iostream>
using namespace std;
int main(void)
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        string str;
        cin>>str;
        int i,j,a[26]={0},cost=0,u;
        u=str.length();
        for(i=0;i<u;i++)
            a[str[i]%97]++;
        //replace:
        for(i=0;i<=25;i++)
        {
            if(a[i]!=0)
            {
                    if(a[i]>i+1)
            {
                for(j=0;j<=25;j++)
                {
                    if(a[j]<j+1)
                    {
                        a[j]++;
                        a[i]--;
                        cost++;
                        if(a[i]==i+1)
                            break;
                    }
                }
            }
            }
        }
        //add:
        for(i=0;i<=25;i++)
        {
            if(a[i]!=0)
            {
                    if(a[i]<i+1)
            {
                cost+=(i+1-a[i]);
                a[i]=i+1;
            }
            }
        }
        //delete:
        for(i=0;i<=25;i++)
        {
            if(a[i]!=0)
            {
                if(a[i]>i+1)
            {
                cost+=(a[i]-i-1);
            }
            }
        }
        /*for(i=0;i<=25;i++)
            cout<<i<<" "<<a[i]<<endl;*/
        cout<<cost<<endl;
    }
    return 0;
}
