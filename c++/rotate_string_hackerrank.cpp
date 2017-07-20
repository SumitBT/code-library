#include<iostream>
using namespace std;
int main(void)
{
string str;
cin>>str;
int i,j;
cout<<str.length()<<endl;
for(i=1;i<=str.length();i++)
{
cout<<&str[i];
for(j=0;j<i;j++)
{
    cout<<str[j];
}
cout<<" ";
}
}
