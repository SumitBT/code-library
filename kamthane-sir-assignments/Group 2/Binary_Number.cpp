/*
1. Write C++ program for storing binary number using doubly linked lists. Write functions
a) to compute 1‘s and 2‘s complement
b) add two binary numbers
*/
#include<iostream>
#include<string>
using namespace std;
class digit
{
public:
    int d;
    digit *pre;
    digit *next;
};
digit *head=NULL;
digit *ptr=NULL;
digit* a[25];
int ind=0;
int ONE=0;
void ones();
void twos();
void add(string);
int main(void)
{
    string str;
    cout<<"Enter binary number\n";
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        digit *current=new digit;
        a[ind]=current;
        ind++;
        current->d=str[i]%48;
        if(head==NULL)
        {
            head=current;
            current->pre=NULL;
            current->next=NULL;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=current;
            current->pre=ptr;
            current->next=NULL;
        }
    }//stored the binary number in doubly linked list
    int choice=0;
    while(choice!=4)
    {
        cout<<"1. One's compliment of binary number\n";
        cout<<"2. Two's Compliment of binary number\n";
        cout<<"3. Add a binary number in it\n";
        cout<<"4. Quit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            ones();
            cout<<endl;
            break;
        case 2:
            twos();
            break;
        case 3:
            add(str);
            break;
        }
    }
    for(int i=0;i<=ind-1;i++)
        delete a[i];
    return 0;
}
void ones()
{
    ONE=1;
    cout<<"One's compliment: ";
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->d==1)
        {
            ptr->d=0;
            cout<<ptr->d;
        }
        else
        {
            ptr->d=1;
            cout<<ptr->d;
        }
        ptr=ptr->next;
    }
}
void twos()
{
    if(ONE==0)
    {
        cout<<"One's compliment: ";
        ones();
        cout<<endl;
    }
    cout<<"Two's compliment: ";
    int c=1;
    ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    while(ptr!=NULL)
    {
        ptr->d+=c;
        if(ptr->d==2)
            ptr->d=0;
        else c=0;
        ptr=ptr->pre;
    }
    if(c==1)
        cout<<c;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->d;
        ptr=ptr->next;
    }
    cout<<endl;
}
void add(string num1)
{
    string num2;
    cout<<"enter binary number to add\n";
    cin>>num2;
    string str=(num1.size()<num2.size())?num1:num2;
    num1=(num1.size()>=num2.size())?num1:num2;
    num2=str;
    for(int i=1;i<=num1.size()-str.size();i++)
        num2="0"+num2;
    int k=(num1.size()>num2.size())?num1.size():num2.size();
    int mcin=0,mcout=0,sum=0,a[k],j=k-1;
    for(int i=k-1;i>=0;i--)
    {
        sum=0;
        mcout=0;
        sum=num1[i]%48+num2[i]%48;
        if(sum==2)
        {
            sum=0;
            mcout=1;
        }
        sum=sum+mcin;
        if(sum==2)
        {
            sum=0;
            mcout=1;
        }
        a[j]=sum;
        j=j-1;
        mcin=mcout;
    }
    if(mcin==1)
        cout<<"1";
    for(j=0;j<k;j++)
        cout<<a[j];
    cout<<endl;
}
//Author:SUMITBT
