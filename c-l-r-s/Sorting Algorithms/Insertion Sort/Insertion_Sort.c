#include<stdio.h>
main()
{
    int a[]={5,2,9,0,7,5,1},size=7;
    int key,i,j,count=0;
    ////////////Insertion Sort//////////////
        for(i=1;i<size;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0&&key<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
         }
    ////////////////////////////////////////
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
}
