#include<stdio.h>
void main()
{
int i,j,k=4,l,p;
for(i=1;i<=4;i++,k=k+4)
    {
      j=(k/4)%2;
      if(j==0)
        {
           p=k;
         for(l=1;l<=4;l++)
            {
             printf("%3d",p);
             p--;
            }
        }
      else
        {
            p=k-3;
         for(l=1;l<=4;l++)
            {
             printf("%3d",p);
              p++;
             }
        }
     printf("\n");
    }
}