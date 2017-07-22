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
class vertex
{
public:
    int n;
    int t;
    bool special;
    vertex* next;
    vertex()
    {
        n=-1;
        t=-1;
        special=false;
        next=NULL;
    }
    vertex(int c,int z,bool k)
    {
        n=c;
        t=z;
        special=k;
        next=NULL;
    }
};
//custom functions' prototypes ->
int dfs(vertex* a[],string* vs,int c,int s,int t,int k,int n);
//global variables ->
vertex* current;
vertex* ptr;
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
    int n,m,k,i;
    cin>>n>>m>>k;
    vertex* a[n];
    for(i=0;i<n;i++)
        a[i]=NULL;
    int x,y,z;
    for(i=1;i<=m+k;i++)
    {
        cin>>x>>y>>z;
        if(i<=m)
            current=new vertex(y,z,false);
        else current=new vertex(y,z,true);
        if(a[x-1]==NULL)
        {
            a[x-1]=current;
            current->next=NULL;
        }
        else
        {
            ptr=a[x-1];
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=current;
        }
    }
    string* vs=new string[n];
    for(i=0;i<n;i++)
        vs[i]="undiscovered";
    vs[0]="discovered";
    cout<<dfs(a,vs,0,0,0,k,n-1);
    i=0;
    while(i<n)
    {
        ptr=a[i];
        while(ptr!=NULL)
        {
            current=ptr->next;
            delete ptr;
            ptr=current;
        }
        i++;
    }
    delete[] vs;
}
//custom function definitions ->
int dfs(vertex* a[],string* vs,int c,int s,int t,int k,int n)
{
    if(c==n)
    {
        if(s==k)
            return t;
        else return -1;
    }
    else
    {
        int min=1001,tt;
        ptr=a[c];
        while(ptr!=NULL)
        {
            if(vs[ptr->n]=="undiscovered")
            {
                vs[ptr->n]="discovered";
                tt=dfs(a,vs,ptr->n,(ptr->special==true?s+1:s),t+ptr->t,k,n);
                if(tt!=-1)
                    if(tt<min)
                        min=tt;
            }
            ptr=ptr->next;
        }
        return min;
    }
}
