#include<iostream>
using namespace std;
int main(void)
{
    int p;
    cout<<"Enter number of person\n";
    cin>>p;
    int a[p][2],i,j;
    string str;
    cout<<"Enter Time period of "<<p<<" persons in this format : 05AM#12PM \n";
    for(i=0;i<p;i++)
    {
        cout<<"Person "<<i+1<<endl;
        cin>>str;
        a[i][0]=((str[0]%48)*10)+(str[1]%48);
        if(a[i][0]!=12&&str[2]=='P')
            a[i][0]+=12;
        a[i][1]=((str[5]%48)*10)+(str[6]%48);
        if(a[i][1]!=12&&str[7]=='P')
            a[i][1]+=12;
    }
    for(i=0;i<p-1;i++)
    {
        for(j=0;j<p-1;j++)
        {
            if(a[j][1]>a[j+1][1])
            {
                int t1,t2;
                t1=a[j][0];
                t2=a[j][1];
                a[j][0]=a[j+1][0];
                a[j][1]=a[j+1][1];
                a[j+1][0]=t1;
                a[j+1][1]=t2;
            }
        }
    }
    int count=1,l=0;
    for(i=1;i<p;i++)
    {
        if(a[i][0]>=a[l][1])
        {
            count++;
            l=i;
        }
    }
    cout<<"Maximum Profit="<<count*500;
    return 0;
}
