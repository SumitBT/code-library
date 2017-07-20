/**
    @author SumitBT ( SumitTamgale@gmail.com )
    @date 12/08/2016
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
    int n;
    cin>>n;
    int a[n],size=0,t,k,i,m,ans;
    bool found,know=false;
    for(t=1;t<=n;t++)
    {
        char ch1;
        int x;
        cin>>ch1;
        {
            if(ch1=='+')
            {
                size++;
                cin>>x;
                a[size-1]=x;
                found=false;
                for(k=size-1;k>=0;k--)
                {
                    m=1;
                    for(i=k-1;i>=0;i--)
                    {
                        if(a[i]==a[size-m])
                            m++;
                        else break;
                    }
                    if(i==-1)
                    {
                        found=true;
                        know=true;
                        cout<<k<<endl;
                        ans=k;
                        break;
                    }
                }
                if(!found)
                {
                    know=false;
                    cout<<0<<endl;
                }

            }
            else
            {
                size--;
                if(size==0)
                {
                    cout<<0<<endl;
                }
                else
                {
                    if(know&&ans>=1)
                        cout<<--ans;
                    else
                    {
                        for(k=size-1;k>=0;k--)
                        {
                            m=1;
                            for(i=k-1;i>=0;i--)
                            {
                                if(a[i]==a[size-m])
                                    m++;
                                else break;
                            }
                            if(i==-1)
                            {
                                found=true;
                                know=true;
                                cout<<k<<endl;
                                ans=k;
                                break;
                            }
                        }
                        if(!found)
                        {
                            know=false;
                            cout<<0<<endl;
                        }
                    }
                }
            }
        }
    }
}
//custom functions' definitions ->
