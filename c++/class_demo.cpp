#include<string>
#include<iostream>
using namespace std;
class student
{
private:
    int roll;
    string name;
    int marks;
public:
    student()
    {
        cout<<"default constructor"<<endl;
    }
    student(int r,string str,int m=98)
    {
        this->roll=r;
        this->name=str;
        this->marks=m;
    }
    void show()
    {
        cout<<this->roll<<endl<<this->name<<endl<<this->marks;
    }
    bool operator >(student st)
    {
        bool re;
        if(this->marks>st.marks)
        {
            re=true;
        }
        else re=false;
        return re;
    }
};
int main()
{
    cout<<"enter roll,name and mark of student"<<endl;
    int roll,marks;
    string name;
    cin>>roll;
    cin.get();
    getline(cin,name);
    cin>>marks;
    student sumit(roll,name);
    student tushar(20,"tushar",99);
    tushar.show();
    sumit.show();
    if(sumit>tushar)
    {
        cout<<"Sumit has more marks than tushar"<<endl;
    }
    return 0;
}
