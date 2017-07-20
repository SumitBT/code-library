#include<stdio.h>
void merge_sort(int*,int,int);
void merge(int*,int,int,int);
main()
{
    int s,p,r;
    printf("Enter size of array\n");
    scanf("%d",&s);
    int a[s],i;
    printf("Enter %d elements\n",s);
    for(i=0;i<=s-1;i++)
        scanf("%d",&a[i]);
    p=0;
    r=s-1;
    merge_sort(a,p,r);
    for(i=0;i<=s-1;i++)
        printf("%d ",a[i]);
}
void merge_sort(int *a,int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void merge(int *a,int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int left[n1+1],right[n2+1];
    for(i=0;i<=n1-1;i++)
        left[i]=a[p+i];
    for(j=0;j<=n2-1;j++)
        right[j]=a[q+j+1];
    left[n1]=10000;
    right[n2]=10000;
    //Merge Process:
    i=j=0;
    for(k=p;k<=r;k++)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
        }
    }
}
