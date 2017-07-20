/**
    @author SumitBT ( SumitTamgale@gmail.com )
    @version 1.0
    @date 09/08/2016
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

//global variables ->

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
    int n;
    cin>>n;
    int a[n],i,max=0,sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]>max)
            max=a[i];
    }
    sum-=max;
    if(max>=sum)
        cout<<1;
    else cout<<0;
}
//custom function definitions ->
