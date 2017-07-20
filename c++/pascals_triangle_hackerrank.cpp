#include<iostream>
using namespace std;
int fact(int);
int main(void)
{
    cout<<"Enter number of lines\n";
    int n;
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int fact(int i)
{
    if(i==1||i==0)
        return 1;
    else return i*fact(i-1);
}
