#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int factorial(unsigned int n)
{
    static int *f=NULL;
    static unsigned int cur=0;
    if(!f)
    {
        f=(int *)malloc(1*sizeof(int));
        f[0]=1;
    }
    if(n>cur)
    {
        f=(int *)realloc(f,(n+1)*sizeof(int));
        for(unsigned int i=cur+1;i<=n;i++)
            f[i]=f[i-1]*i;
        cur=n;
    }
    return f[n];
}
int rank(char *str, int n)
{
    int result=0;
    for(int i=0;i<9;i++)
    {
        int count=0;
        for(int j=i+1;j<10;j++)
            if(str[i]>str[j])
                count++;
        if(count>0)
            result+=(9-i)*factorial((unsigned int)count);
    }
    return result+1;
}
int main()
{
    int t;
    char a[11];
    cin>>t;
    long long ans=1;
    for(int i=0;i<t;i++)
    {
        scanf("%s",a);
        ans*=rank(a,10);
    }
    cout<<ans%23456;
    return 0;
}