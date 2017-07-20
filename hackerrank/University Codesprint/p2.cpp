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
	int n,k,i,j;
    cin>>n>>k;
    int a1[n],max=0,min=1000000,x;
    for(i=0;i<n;i++)
    {
        cin>>a1[i];
        if(a1[i]>max)
            max=a1[i];
        if(a1[i]<min)
            min=a1[i];
    }
    int d=max-min+1;
    int a[d];
    for(i=0;i<d;i++)
        a[i]=0;
    for(i=0;i<n;i++)
    {
        a[a1[i]-min]=1;
    }
    int count=0;
    for(i=0;i<d;)
    {
        if(a[i]==1)
        {
            for(j=i+k;j>=i;j--)
            {
                if(a[j]==1)
                {
                    count++;
                    i=j+k+1;
                }
            }
        }
    else i++;
    }
    cout<<count;
}
//custom functions' definitions ->
