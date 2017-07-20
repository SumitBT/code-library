/**
    @author SumitBT ( SumitTamgale@gmail.com )
    @version 1.0
    @date 07/08/2016
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
class CommandLineArguments
{
private:
    int NumberOfArguments;
    string *Arguments;
public:
    CommandLineArguments(int l,char **ptr)
    {
        this->NumberOfArguments=l;
        Arguments=new string[l];
        for(int i=1;i<=l;i++)
            Arguments[i-1]=string(ptr[i]);
    }
    void DeleteArguments()
    {
        delete[] this->Arguments;
    }
    string operator[](int i)
    {
        if(i>=0&&i<this->NumberOfArguments)
            return this->Arguments[i];
        else return NULL;
    }
    int length()
    {
        return this->NumberOfArguments;
    }
};
void run(CommandLineArguments);
//custom classes ->

//custom functions' prototypes ->

//main function->
int main(int argc, char **argv)
{
    CommandLineArguments cla(argc-1,argv);
    run(cla);
    cla.DeleteArguments();
	return 0;
}
//run function ->
void run(CommandLineArguments args)
{
    //Start coding here ->
    long long n,c=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(n%i!=0)
            if((n%i)*(n%i)%i==0)
                c++;
    }
    cout<<c;
}
//custom function definitions ->
