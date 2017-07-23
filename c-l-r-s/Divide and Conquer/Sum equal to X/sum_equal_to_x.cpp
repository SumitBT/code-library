/*
Problem Statement:
Give a O(n lg(n))-time algorithm that, given a set S of n integers and another integer x,
determines whether or not there exist two elements in S whose sum is exactly x.
*/
#include<iostream>
using namespace std;
int x;
void divide(int*,int,int);
void check(int*,p,q,r);
int main(void)
{
    int s;
    cout<<"Enter size of set\n";
    cin>>s;
    int a[s],i;
    for(i=0;i<s;i++)
        cin>>a[i];
    cout<<"Enter x\n";
    cin>>x;
    divide(a,0,s-1);
    return 0;
}
void divide(int*a,int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        divide(a,p,q);
        divide(a,q+1,r);
        check(a,p,q,r);
    }
}
void check(int *a,int p,int q,int r)
{
    int left[q-p+1],right[r-q];

}
