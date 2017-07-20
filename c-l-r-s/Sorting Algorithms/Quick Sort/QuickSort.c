#include<stdio.h>
void quicksort(int*,int,int);
void main()
{
    int a[]={2,8,7,1,3,5,6,4};
    int i;
    quicksort(a,0,7);
    for(i=0;i<=7;i++)
        printf("%d ",a[i]);
}
void quicksort(int*a,int p,int r)
{
    if(p<r)
    {
        int x=a[r];//pivot
        int k,q;
        int i=p-1,j;
        //Partitioning:
        for(j=p;j<=r-1;j++)
        {
            if(a[j]<=x)
            {
                i++;
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
        k=a[i+1];
        a[i+1]=a[r];
        a[r]=k;
        q=i+1;//pivot index
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
