#include<iostream>
using namespace std;
int main(void)
{
    int r,l;
    cin>>r;
    string str;
    char last;
    bool flag;
    for(int R=1;R<=r;R++)
    {
        cin>>l;
        cin>>str;
        flag=false;
        last='T';
        for(int i=0;i<l;i++)
        {
            if(i==l-1&&last=='H'&&str[i]!='T')
            {
                cout<<"Invalid";
                flag=true;
                break;
            }
            if(str[i]=='T')
            {
                if(last=='T')
                {
                    cout<<"Invalid";
                    flag=true;
                    break;
                }
                last='T';
            }
            else if(str[i]=='H')
            {
                if(last=='H')
                {
                    cout<<"Invalid";
                    flag=true;
                    break;
                }
                last='H';
            }
        }
        if(!flag)
        {
            cout<<"Valid";
        }
        if(R!=r)
            cout<<endl;
    }
    return 0;
}
