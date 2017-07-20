/**
    @author SumitBT ( SumitTamgale@gmail.com )
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
    string *ArgumentsList;
public:
    CommandLineArguments(int l,char **ptr)
    {
        this->NumberOfArguments=l;
        ArgumentsList=new string[l];
        for(int i=1;i<=l;i++)
            ArgumentsList[i-1]=string(ptr[i]);
    }
    void DeleteArguments()
    {
        delete[] this->ArgumentsList;
    }
    string operator[](int i)
    {
        if(i>=0&&i<this->NumberOfArguments)
            return this->ArgumentsList[i];
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

//main function ->
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
    //start here ->
	long long sum=0,max=0,min=1000000001,k;
    for(int i=1;i<=5;i++)
        {
        cin>>k;
        sum+=k;
        if(k<min)
            min=k;
        if(k>max)
            max=k;
    }
    cout<<sum-max<<" ";
    cout<<sum-min;
}
//custom functions' definitions ->
