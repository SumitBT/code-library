#include<iostream>
using namespace std;
int* a;
int main(void)
{
    a=new int[4];
    a[0][0]=5;
    delete a;
    return 0;
}
