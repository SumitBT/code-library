#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    long long count=0;
    cin>>str;
    for(int i=0;i<str.length()-3;i++)
        {
        for(int l=str.length()-1;l>=i+3;l--)
            {
             if(str[i]==str[l])
                 {
                 for(int j=i+1;j<l-2;j++)
                    {
                    for(int k=l-1;k>=j+1;k--)
                        {
                        if(str[j]==str[k])
                         {
                            count++;
                        }
                       }
                }
             }
        }
    }
    cout<<count%1000000007;
    return 0;
}
