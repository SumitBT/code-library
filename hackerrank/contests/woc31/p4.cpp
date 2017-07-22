#include<iostream>
using namespace std;
class vertex
{
public:
    int n;
    vertex* next;
    bool flag;
    vertex()
    {
        n=-1;
        next=NULL;
        flag=false;
    }
};
vertex* ptr;
vertex* current;
int main(void)
{
    int v,e;
    cin>>v>>e;
    vertex** graph = new vertex*[v];
    for(int i=0;i<v;i++)
        graph[i]=NULL;
    int e1,e2,r[v][v][2];
    for(int i=1;i<=e;i++)
    {
        cin>>e1>>e2;
        cin>>r[e1][e2][0]>>r[e1][e2][1];
        r[e2][e1][0]=r[e1][e2][0];
        r[e2][e1][1]=r[e1][e2][1];
        current = new vertex;
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
    /*
    for(int i=0;i<v;i++)
    {
        cout<<i;
        ptr=graph[i];
        while(ptr!=NULL)
        {
            cout<<"-"<<r[i][ptr->n][0]<<","<<r[i][ptr->n][1]<<"->"<<ptr->n;
            ptr=ptr->next;
        }
        cout<<endl;
    }
    */
    for(int i=0;i<v;i++)
        graph[i]->flag=false;
    int maxa=1,minb=1;
    vertex* temp;
    for(int i=0;i<v;i++)
    {
        if(!graph[i]->flag)
        {
            graph[i]->flag=true;
            ptr=graph[i]->next;
            int tempa,tempb,tempmax;
            tempa=r[i][ptr->n][0];
            tempb=r[i][ptr->n][1];
            tempmax=tempa-tempb;
            temp=ptr;
            ptr=ptr->next;
            while(ptr!=NULL)
            {
                if(r[i][ptr->n][0]-r[i][ptr->n][1]>tempmax)
                {
                    tempa=r[i][ptr->n][0];
                    tempb=r[i][ptr->n][1];
                    tempmax=tempa-tempb;
                    temp=ptr;
                }
                ptr=ptr->next;
            }
            temp->flag=true;
            cout<<tempa<<" "<<tempb;
            maxa+=tempa;
            minb+=tempb;
        }
    }
    cout<<maxa<<"/"<<minb;
    return 0;
}
