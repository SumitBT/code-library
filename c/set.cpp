#include<iostream>
#include<cstdlib>
using namespace std;
void reset(int *array,int num)
{
    for(int i=0;i<num;i++)
    {
        array[i]=0;
    }
}
void print(int *array,int num)
{
    for(int i=0;i<num;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int num,sum=0,level,temp,count=1;
    register int i,j;
    cin>>num;
    if(num<=0)
    {
        cout<<"Get Lost";
        exit(EXIT_SUCCESS);
    }
    int *array=(int*)calloc(num,sizeof(int));
    int *aux=(int*)calloc(num,sizeof(int));
    int *index=(int*)calloc(num,sizeof(int));
    if(array==NULL || aux==NULL || index==NULL)
    {
        cout<<"Error Allotting Memory";
        exit(EXIT_FAILURE);
    }
    for(i=0;i<num;i++)
    {
        array[i]=i+1;
    }
    for(i=0;i<num;i++)
    {
        index[0]=i;
        aux[0]=array[i];
        sum=array[i];
        level=1;
        for(j=i+1;j<num;j++)
        {
            if(sum+array[j]==num)
            {
                count++;
                aux[level]=array[j];
                index[level]=j;
                print(aux,level+1);
                level--;
                if(level==0)
                {
                    break;
                }
                sum-=aux[level];
                j=index[level];
            }
            else if(sum+array[j]>num)
            {
                level--;
                sum-=aux[level];
                j=index[level];
                if(level==0)
                {
                    break;
                }
            }
            else if(sum+array[j]<num)
            {
                sum+=array[j];
                aux[level]=array[j];
                index[level]=j;
                level++;
            }
        }
        reset(aux,num);
    }
    cout<<endl<<count;
    return 1;
}
