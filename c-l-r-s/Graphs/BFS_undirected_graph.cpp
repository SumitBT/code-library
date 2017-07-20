#include<iostream>
#include<string>
using namespace std;
int ct=0;
class myqueue
{
private:
    int a[100];
    int head;
    int tail;
public:
    int N;
    myqueue()
    {
        head=0;
        tail=0;
        N=0;
    }
    void enqueue(int i)
    {
        if(N==100)
            cout<<"Overflow!\n";
        else
        {
            if(this->tail==100)
                this->tail=0;
            a[this->tail++]=i;
            N++;
        }
    }
    int dequeue()
    {
        if(N==0)
        {
            cout<<"Underflow!\n";
            return 0;
        }
        else
        {
            if(this->head==100)
            this->tail=0;
            return a[this->head++];
            N--;
        }
    }
};
class vertex
{
public:
    int n;
    vertex* next;
    vertex()
    {
        n=-1;
        next=NULL;
    }
};
vertex* ptr;
vertex* current;
vertex* a[50];
int ind=0;
int main(void)
{
    cout<<"Enter number of vertex\n";
    int v;
    cin>>v;
    vertex** graph=new vertex*[v];
    for(int i=0;i<v;i++)
        graph[i]=NULL;
    cout<<"Enter number of edges\n";
    int e;
    cin>>e;
    int e1,e2;
    for(int i=1;i<=e;i++)
    {
        cout<<"enter edge number "<<i<<endl;
        cin>>e1>>e2;
        e1--;e2--;
        current = new vertex;
        a[ind++]=current;
        current->n=e2;
        if(graph[e1]==NULL)
            graph[e1]=current;
        else
        {
            ptr=graph[e1];
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=current;
        }
        current = new vertex;
        a[ind++]=current;
        current->n=e1;
        if(graph[e2]==NULL)
            graph[e2]=current;
        else
        {
            ptr=graph[e2];
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=current;
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<i+1;
        ptr=graph[i];
        while(ptr!=NULL)
        {
            cout<<"->"<<ptr->n+1;
            ptr=ptr->next;
        }
        cout<<endl;
    }
    cout<<endl;
    //BFS:
    cout<<"Enter number of source vertex\n";
    int s;
    cin>>s;
    string* vertex_status=new string[v];
    for(int i=0;i<v;i++)
        vertex_status[i]="undiscovered";
    vertex_status[s-1]="discovered";
    myqueue q1;
    q1.enqueue(s-1);
    int u;
    while(q1.N>=0)
    {
        u=q1.dequeue();
        if(vertex_status[u]!="completed")
        {
            cout<<u+1<<" ";
            ct++;
            if(ct==v)
                break;
            vertex_status[u]="completed";
            ptr=graph[u];
            while(ptr!=NULL)
            {
                if(vertex_status[ptr->n]=="undiscovered")
                {
                    vertex_status[ptr->n]="discovered";
                    q1.enqueue(ptr->n);
                }
                ptr=ptr->next;
            }
        }
    }
    ////
    for(int i=0;i<ind;i++)
        delete a[i];
    delete [] graph;
    delete [] vertex_status;
    return 0;
}
