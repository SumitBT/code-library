/**
    @author SumitBT ( SumitTamgale@gmail.com )
    @version 1.0
    @date 06/08/2016
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
    int n,d,i,j,k;
    cin>>n>>d;
    int a1[n],a2[d];
    for(i=0;i<n;i++)
        cin>>a1[i];
    for(i=0;i<d;i++)
        cin>>a2[i];
    for(k=0;k<d;k++)
    {
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(a1[i]-a1[j]==a2[k])
                {
                    cout<<j+1<<" "<<i+1<<endl;
                    goto here;
                }
            }
        }
        cout<<-1<<endl;
        here:;
    }
}
//custom functions' definitions ->
