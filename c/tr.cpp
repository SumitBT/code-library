#include<iostream>
using namespace std;
int* ret(int*);
int main()
{
  int i=1,*p,*q;
p=&i;
q=*ret(p);
cout<<*q;
return 0;
}
int* ret(int* r)
{
return r;
}