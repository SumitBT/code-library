#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(void)
{
srand(time(0));
cout<<rand()%10<<endl;
cout<<rand()%10+1;
return 0;
}
