#include<iostream>
using namespace std;
int call();
int main(void)
{
    int i=9;
    if(i==1||call()==0)
        cout<<"done\n";
    return 0;
}
int call()
{
    cout<<"in call\n";
    return 0;
}
