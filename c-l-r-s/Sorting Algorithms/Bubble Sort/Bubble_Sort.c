#include<stdio.h>
main()
{
    int a[]={5,2,9,0,7,5,1},size=7;
    int i,j,k;
    ////////////////Bubble Sort/////////////////
    
         for(i=0;i<size-1;i++)          
         {                              
             for(j=0;j<size-1-i;j++)    
             {                          
                 if(a[j]>a[j+1])        
                 {                      
                    k=a[j];             
                    a[j]=a[j+1];        
                    a[j+1]=k;           
                  }                     
              }
         }
    
    ////////////////////////////////////////////
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
}
