/*
5. Department of Computer Engineering has student's club named 'Pinnacle Club'.
Students of Second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of club
and last node is reserved for secretary of club. Write C++ program to maintain club member‘s
information using singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as president or even
secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two
lists.
*/
#include<iostream>
#include<string>
using namespace std;
class member
{
public:
    string PRN;
    string name;
    member *next;
    void initialize(string str1,string str2,member* m)
    {
        this->PRN=str1;
        this->name=str2;
        this->next=m;
    }
};
member *president;
member *secretary;
member *ptr;
member* a[10];
int ind=0;
void add();
void deletem();
void display();
void reverse_display(member*);
void quit();
int main(void)
{
    president=new member;
    secretary=new member;
    president->initialize("2014BCS040","President",secretary);
    a[ind]=president;
    ind++;
    secretary->initialize("2014BCS000","Secretary",NULL);
    a[ind]=secretary;
    ind++;
    int choice=0;
    while(choice!=5)
    {
        cout<<"1. Add Member\n";
        cout<<"2. Delete Member\n";
        cout<<"3. Display Members\n";
        cout<<"4. Display Members in reverse order\n";
        cout<<"5. Delete All Appointments and Quit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            deletem();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse_display(secretary);
            break;
        }
    }
    quit();
    return 0;
}
void add()
{
    member *current = new member;
    a[ind]=current;
    ind++;
    cout<<"Enter PRN\n";
    cin>>current->PRN;
    cin.get();
    cout<<"Enter name\n";
    char str[35];
    cin.getline(str,35);
    current->name=str;
    ptr=president;
    while(ptr->next!=secretary)
        ptr=ptr->next;
    current->next=ptr->next;
    ptr->next=current;
}
void deletem()
{
    string str;
    cout<<"Enter PRN\n";
    cin>>str;
    member *pre=NULL;
    ptr=president;
    while(ptr!=NULL)
    {
        if(ptr->PRN==str)
        {
            if(pre!=NULL)
            {
                pre->next=ptr->next;
            }
            else
            {
                president=ptr->next;
            }
        }
        pre=ptr;
        ptr=ptr->next;
    }
}
void display()
{
    cout<<endl;
    ptr=president;
    while(ptr!=NULL)
    {
        cout<<ptr->PRN<<" ";
        cout<<ptr->name<<endl;
        ptr=ptr->next;
    }
    cout<<endl;
}
void reverse_display(member *t)
{
    member *pre=NULL;
    ptr=president;
    while(ptr!=t)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    cout<<ptr->PRN<<" "<<ptr->name<<endl;
    if(pre!=NULL)
    reverse_display(pre);//recursion
}
void quit()
{
    for(int i=0;i<=ind-1;i++)
    {
        delete a[i];
    }
    cout<<"Members data cleared";
}
//Author:SUMITBT
