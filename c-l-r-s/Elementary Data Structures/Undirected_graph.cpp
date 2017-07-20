#include<iostream>
using namespace std;
class vertex
{
public:
    int n;
    string colour;
    vertex* next;
    vertex()
    {
        n=-1;
        colour="white";
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
        cout<<i+1<<"->";
        ptr=graph[i];
        while(ptr!=NULL)
        {
            cout<<ptr->n+1<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    for(int i=0;i<ind;i++)
        delete a[i];
    delete [] graph;
    return 0;
}
