/*
7. Pizza parlor accepting maximum M orders. Orders are served in first
come first served basis. Order once placed cannot be cancelled.
Write C++ program to simulate the system using circular queue using
array
*/
#include<iostream>
using namespace std;
int N=0,head=-1,tail=0,m;
void place(int*);
void complete(int*);
int main(void)
{
    cout<<"Enter value of m\n";
    cin>>m;
    int q[m];
    int choice=0;
    while(choice!=3)
    {
        cout<<"1. Place order\n";
        cout<<"2. Withdraw next Order\n";;
        cout<<"3. Quit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            place(q);
            break;
        case 2:
            complete(q);
            break;
        }
    }
    return 0;
}
void place(int *q)
{
    if(N==m)
        cout<<"Queue Overflow\n";
    else
    {
        cout<<"Enter number of Pizza\n";
        cin>>q[tail++];
        N++;
        cout<<"Placed!\n";
    }
    if(tail==m)
        tail=0;
}
void  complete(int *q)
{
    if(N==0)
        cout<<"Queue Underflow!\n";
    else
    {
        cout<<"Next order is of "<<q[++head]<<" pizza\n";
        N--;
    }
    if(head==m-1)
        head=-1;
}
//Author:SUMITBT
