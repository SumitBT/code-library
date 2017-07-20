/*
4. The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained
to keep track of free seats at rows. Assume some random booking to start with. Use array to
store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class free_seat
{
public:
    int seat_no;
    free_seat *pre;
    free_seat *next;
    free_seat()
    {
        seat_no=0;
        pre=NULL;
        next=NULL;
    }
};
free_seat *ptr=NULL;
free_seat* head[10]={NULL};
free_seat* a[70];
int ind=0;
void show();
void book();
void cancel();
void quit();
int main(void)
{
    srand(time(0));
    for(int i=0;i<=9;i++)
    {
        int r=(rand()%6)+2;
        int r2=(rand()%6)+2;
        for(int j=1;j<=r;j++)
        {
            free_seat* current = new free_seat;
            a[ind]=current;
            ind++;
            current->seat_no=(++r2%7)+1;
            if(head[i]==NULL)
            {
                head[i]=current;
                current->pre=NULL;
                if(j==r)
                {
                    current->next=head[i];
                    head[i]->pre=current;
                }
            else current->next=NULL;
            }
            else
            {
                ptr=head[i];
            while(ptr->next!=NULL)
                ptr=ptr->next;

            ptr->next=current;
            current->pre=ptr;
            if(j==r)
            {
                current->next=head[i];
                head[i]->pre=current;
            }
            else current->next=NULL;
            }
        }
    }
    //random booking created
    int choice=0;
    while(choice!=4)
    {
        cout<<"1. List of Available Seats\n";
        cout<<"2. Book a Seat\n";
        cout<<"3. Cancel Booking\n";
        cout<<"4. Dlete All Data and Quit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            show();
            break;
        case 2:
            book();
            break;
        case 3:
            cancel();
            break;
        }
    }
    quit();
    return 0;
}
void show()
{
    for(int i=0;i<=9;i++)
    {
        cout<<"row "<<i+1<<" Available seat numbers: ";
        ptr=head[i]->next;
        while(ptr!=head[i])
        {
            cout<<ptr->seat_no<<" ";
            ptr=ptr->next;
        }
        cout<<ptr->seat_no<<" ";
        cout<<"\b"<<endl;
    }
}
void book()
{
    cout<<"Enter row number and seat number\n";
    int r,s;
    cin>>r>>s;
    ptr=head[r-1];
    while(ptr->next!=NULL)
    {
        if(ptr->seat_no==s)
        {
            ptr->pre->next=ptr->next;
            ptr->next->pre=ptr->pre;
            cout<<"Booked!\n";
            return;
        }
        ptr=ptr->next;
    }
    cout<<"Seat is already booked\n";
}
void cancel()
{
    int r,s;
    cout<<"Enter row number and seat number\n";
    cin>>r>>s;
    ptr=head[r-1];
    while(ptr!=head[r-1]->pre)
    {
        if(ptr->seat_no==s)
        {
            cout<<"unbooked seat can't be canceled\n";
            return;
        }
        ptr=ptr->next;
    }
    free_seat* current = new free_seat;
    a[ind]=current;
    ind++;
    current->seat_no=s;
    ptr->next=current;
    head[r-1]->pre=current;
    current->pre=ptr;
    current->next=head[r-1];
    cout<<"Canceled!\n";
}
void quit()
{
    for(int i=0;i<=ind-1;i++)
    {
        delete a[i];
    }
    cout<<"All booking Cleared";
}
//Author:SUMITBT
