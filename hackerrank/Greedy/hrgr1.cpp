#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i1,i2,num,key,j;
    cin>>n;
    int a[n][2];
    for(int t=0;t<n;t++)
        {
        cin>>i1>>i2;
        num=i1+i2;
        //key=num;
            j=t-1;
            while(j>=0&&num<a[j][0])
            {
                a[j+1][0]=a[j][0];
                j--;
            }
            a[j+1][0]=num;
            a[j+1][1]=t+1;
    }
    for(int i=0;i<n;i++)
        cout<<a[i][1]<<" ";
    return 0;
}

