#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t,T;
    cin>>T;
    for(t=1;t<=T;t++)
        {
        string str,str2,str3;
        cin>>str;
        for(int i=0;i<str.length();i=i+2)
        str2+=str[i];
    cout<<str2<<endl;
    for(int i=1;i<str.length();i=i+2)
        str3+=str[i];
    cout<<str3;
    }

    return 0;
}
