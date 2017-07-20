/*
3.	Write C++ program for storing appointment schedule for day. Appointments are
booked randomly using linked list. Set start and end time and min and max duration
for visit slot. Write functions for-
a) Display free slots
b) Book appointment
c) Cancel appointment (check validity, time bounds, availability etc)
d) Sort list based on time
e) Sort list based on time using pointer manipulation
*/
#include<iostream>
using namespace std;
const int START_TIME=10;
const int END_TIME=18;
const int MIN_TIME=1;
const int MAX_TIME=5;
class appointment
{
public:
    int start_time;
    int end_time;
    appointment *pre;
    appointment *next;
    appointment()
    {
        start_time=0;
        end_time=0;
        pre=NULL;
        next=NULL;
    }
    void initialize(int st,int et,appointment *p,appointment *q)
    {
        start_time=st;
        end_time=et;
        pre=p;
        next=q;
    }
};
appointment *head;
appointment *last;
appointment *ptr=NULL;
appointment* a[100];
int ind=0;
void slots();
void create();
void cancel();
void app_list();
void quit();
int main(void)
{
    head = new appointment();
    a[ind]=head;
    ind++;
    last = new appointment();
    a[ind]=last;
    ind++;
    head->initialize(-1,START_TIME,NULL,last);
    last->initialize(END_TIME,-1,head,NULL);
    int choice=0;
    while(choice!=5)
    {
        cout<<"1. Show Open Slots\n";
        cout<<"2. Create Appointment\n";
        cout<<"3. Cancel Appointment\n";
        cout<<"4. Show Sorted Appointment List based on time\n";
        cout<<"5. Delete All Appointments and Quit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            slots();
            break;
        case 2:
            create();
            break;
        case 3:
            cancel();
            break;
        case 4:
            app_list();
            break;
        }
    }
    quit();
    return 0;
}
void slots()
{
    ptr=head;
    while(ptr!=last)
    {
        if(ptr->next->start_time-ptr->end_time!=0)
        {
            if(ptr->end_time>12)
            cout<<ptr->end_time-12;
            else cout<<ptr->end_time;
            if(ptr->next->start_time>12)
            cout<<"-"<<ptr->next->start_time-12<<endl;
            else cout<<"-"<<ptr->next->start_time<<endl;
        }
        ptr=ptr->next;
    }
}
void create()
{
    int s,e;
    cout<<"Enter Start Time\n";
    cin>>s;
    if(s<10)
        s+=12;
    cout<<"Enter End Time\n";
    cin>>e;
    if(e<10)
        e+=12;
    if(e<s||e-s>MAX_TIME||e-s<MIN_TIME)
    {
        cout<<"Wrong input, Try Again\n";
        return;
    }
    ptr=head->next;
    while(ptr!=last)
    {
        if((ptr->start_time==s&&ptr->end_time==e)||(ptr->start_time<s&&ptr->end_time>s)||(ptr->start_time<e&&ptr->end_time>e))
        {
            cout<<"Wrong input, Try Again\n";
            return;
        }
        ptr=ptr->next;
    }
    appointment *current = new appointment;
    a[ind]=current;
    ind++;
    current->start_time=s;
    current->end_time=e;
    ptr=head;
    while(ptr!=last)
    {
        if(current->start_time>=ptr->end_time&&current->end_time<=ptr->next->start_time)
        {
            current->pre=ptr;
            current->next=ptr->next;
            ptr->next=current;
            current->next->pre=current;
        }
        else
        ptr=ptr->next;
    }
}
void cancel()
{
    cout<<"Enter Start time of the appointment to be cancelled\n";
    int s,e;
    cin>>s;
    cout<<"Enter end time\n";
    cin>>e;
    if(e<10)
        e+=12;
    if(s<10)
        s+=12;
    ptr=head->next;
    while(ptr!=last)
    {
        if(ptr->start_time==s&&ptr->end_time==e)
        {
            ptr->pre->next=ptr->next;
            ptr->next->pre=ptr->pre;
            return;
        }
        ptr=ptr->next;
    }
    cout<<"No Such Appointment Exists\n";
}
void app_list()
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr!=head&&ptr!=last)
        {
            if(ptr->start_time>12)
                cout<<ptr->start_time-12;
            else cout<<ptr->start_time;
            if(ptr->end_time>12)
                cout<<"-"<<ptr->end_time-12<<endl;
            else cout<<"-"<<ptr->end_time<<endl;
        }
        ptr=ptr->next;
    }
}
void quit()
{
    for(int i=0;i<=ind-1;i++)
    {
        delete a[i];
    }
    cout<<"Appointments cleared";
}
//Author:SUMITBT
