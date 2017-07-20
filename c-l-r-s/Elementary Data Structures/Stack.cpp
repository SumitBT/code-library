#include<iostream>
#include<string>
using namespace std;
const int MAX_STACK_SIZE=25;
int stck[MAX_STACK_SIZE];
int top=-1;
void push(int n);
void pop();
int main(void)
{
    string str="start";
    cout<<"push n : to push n onto your stack\n";
    cout<<"pop : to pop the top element of stack\n";
    cout<<"quit : to quit and clear the stack\n";
    cout<<"We ignore wrongly typed actions\n";
    while(str!="quit")
    {
        cout<<"Take Action:\n";
        cin>>str;
        if(str=="push")
        {
            int n;
            cin>>n;
            push(n);
        }
        else if(str=="pop")
        {
            pop();
        }
    }
    cout<<"Stack Cleared...!";
    return 0;
}
void push(int n)
{
    if(top<MAX_STACK_SIZE)
        {
            top++;
            stck[top]=n;
        }
    else cout<<"Error! Stack Overflow...\n";
}
void pop()
{
    if(top>=0)
    {
        cout<<stck[top]<<endl;
        top--;
    }
    else cout<<"Error! Stack Underflow...\n";
}
