#include<stdio.h>
void heap_sort(int*);
void create_max_heap(int*,int);
int heap_size=5;
main()
{
    int a[]={4,0,8,9,5,1},i;
    heap_sort(a);
    for(i=0;i<=5;i++)
        printf("%d ",a[i]);
}
//Heap Sort
void heap_sort(int *a)
{
    int i,k;
    for(i=2;i>=0;i--)
        create_max_heap(a,i);
    for(i=5;i>=1;i--)
    {
        k=a[i];
        a[i]=a[0];
        a[0]=k;
        heap_size--;
        create_max_heap(a,0);
    }
}
create_max_heap(int *a,int i)
{
    int l=2*i,r=(2*i)+1,largest,k;
    if(l<=heap_size&&a[l]>=a[i])
        largest=l;
    else largest=i;
    if(r<=heap_size&&a[r]>=a[largest])
        largest=r;
    if(largest!=i)
    {
        k=a[i];
        a[i]=a[largest];
        a[largest]=k;
        create_max_heap(a,largest);
    }
}
