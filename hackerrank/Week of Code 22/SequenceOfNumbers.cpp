/**
    @author SumitBT ( SumitTamgale@gmail.com )
    @date 11/08/2016
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
    int n,i,c=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        if(a[i]==-1)
            c++;
    }
    bool found=false;
    for(i=1;i<=n;i++)
    {
        if(a[i-1]!=-1)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                if(a[i-1]!=a[j-1]%i)
                {
                    found=true;
                    goto here;
                }
            }
        }
    }
    here:
        if(found)
            cout<<0;
        else
            {
            int s[c],j=0;
            for(i=0;i<n;i++)
                if(a[i]==-1)
                    s[j++]=i+1;
            cout<<1;
            }
}
//custom functions' definitions ->
