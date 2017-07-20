#include<iostream>
#include<string>
using namespace std;
void insertion();
void deletion();
void traversal();
void searching();
class node
{
public:
    int key;
    node *pre;
    node *next;
    node()
    {
        key=0;
        pre=NULL;
        next=NULL;
    }
};
node *head=NULL;
node *ptr=NULL;
node* a[10];
int ind=0;
int main(void)
{
    string str="start";
    while(str!="quit")
    {
        cout<<"Take Action:\n";
        cin>>str;
        if(str=="insert")
            insertion();
        else if(str=="delete")
            deletion();
        else if(str=="traverse")
            traversal();
        else if(str=="search")
            searching();
    }
    for(int i=0;i<=ind-1;i++)
    {
        delete a[i];
    }
    cout<<"Linked List cleared\n";
    return 0;
}
void insertion()
{
    int x;
    cin>>x;
    node *current=new node;
    a[ind]=current;
    ind++;
    current->key=x;
    if(head==NULL)
        head=current;
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=current;
        current->pre=ptr;
    }
}
void deletion()
{
    int x;
    cin>>x;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->key==x)
        {
            ptr->pre->next=ptr->next;
            ptr->next->pre=ptr->pre;
            return;
        }
        ptr=ptr->next;
    }
    cout<<"Not Found\n";
}
void traversal()
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->key<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}
void searching()
{
    int x;
    cin>>x;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->key==x)
        {
            cout<<ptr<<endl;
            return;
        }
        ptr=ptr->next;
    }
    cout<<"Not Found\n";
}
