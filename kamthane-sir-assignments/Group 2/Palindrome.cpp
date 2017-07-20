/*
6. A palindrome is a string of character that‘s the same forward and
backward. Typically, punctuation, capitalization, and spaces are
ignored. For example, “Poor Dan is in a droop” is a palindrome, as
can be seen by examining the characters “poor danisina droop” and
observing that they are the same forward and backward. One way to
check for a palindrome is to reverse the characters in the string
and then compare with them the original-in a palindrome, the
sequence will be identical. Write C++ program with functions-
1. to check whether given string is palindrome or not that uses
a stack to determine whether a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the
Characters to lowercase, and then call above Palindrome
checking function to check for a palindrome
3. to print string in reverse order using stack
*/
#include<iostream>
#include<cstring>
using namespace std;
class mystack
{
private:
    char a[100];
public:
    int top;
    mystack()
    {
        top=-1;
    }
    void push(char ch)
    {
        if(this->top==99)
            cout<<"Stack Overflow\n";
        else this->a[++this->top]=ch;
    }
    char pop()
    {
        if(this->top<0)
        {
            cout<<"Stack Underflow\n";
            return -1;
        }
        else return this->a[this->top--];
    }
};
void is_palindrome();
void rev();
int main(void)
{
    int choice=0;
    while(choice!=3)
    {
        cout<<"1. Check whether string is palindrome or not\n";
        cout<<"2. Print reverse string\n";
        cout<<"3. quit\n";
        cout<<"Enter choice: 1 2 3\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            is_palindrome();
            break;
        case 2:
            rev();
            break;
        case 3:
            break;
        }
    }
    return 0;
}
void is_palindrome()
{
    cout<<"Enter String\n";
    cin.get();
    char str[100];
    cin.getline(str,100);
    mystack stk;
    int i;
    bool is_palindrome=true;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]+32;
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='0'&&str[i]<='9'))
            stk.push(str[i]);
    }
    for(int i=0;i<strlen(str);i++)
    {
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='0'&&str[i]<='9'))
            {
                if(str[i]!=stk.pop())
                {
                    cout<<"Not a palindrome\n";
                    is_palindrome=false;
                    break;
                }
            }
    }
    if(is_palindrome==true)
        cout<<"string is palindrome\n";
    cout<<endl;
}
void rev()
{
    cout<<"Enter String\n";
    cin.get();
    char str[100];
    cin.getline(str,100);
    mystack stk;
    for(int i=0;i<strlen(str);i++)
        stk.push(str[i]);
        cout<<"Reverse: ";
    while(stk.top>=0)
        cout<<stk.pop();
    cout<<endl<<endl;
}
//Author:SUMITBT
