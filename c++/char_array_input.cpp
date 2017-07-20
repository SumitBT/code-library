#include<iostream>
#include<string>
#include<cstring>
int main(void)
{
    using namespace std;
    char  a[5][6];
    int i;
    /*for(i=0;i<=4;i++)
    {
        cin.getline(a[i],6);
    }
    for(i=0;i<=4;i++)
    {
        cout<<a[i]<<endl;
    }*/
    string str;
    cout<<"enter string"<<endl;
    getline(cin,str);
    cout<<str<<sizeof str<<endl;
    return 0;
}
