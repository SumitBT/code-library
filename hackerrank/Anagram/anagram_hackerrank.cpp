#include<string>
#include<iostream>
using namespace std;
void doit();
int main(void)
{
    int t;
    cin>>t;
    int i;
    for(i=1;i<=t;i++)
    {
        doit();
    }
    return(0);
}
void doit()
{
    string str;
    cin>>str;
    int a[2][26]={0};
    int count=0;
    if(str.size()%2!=0)
    {
        cout<<"-1"<<endl;
    }
    else if(str.size()%2==0)
    {
        int i;
        for(i=0;i<=str.size()-1;i++)
        {
            if(i<=(str.size()-1)/2)
            {
                a[1][str[i]-97]++;
            }
            else if(i>(str.size()-1)/2)
                {
                    a[0][str[i]-97]++;
                }
        }
        for(i=0;i<=25;i++)
        {
           if(a[0][i]>a[1][i])
           {
                count=count+(a[0][i]-a[1][i]);
           }
        }
        cout<<count<<endl;
    }
}
