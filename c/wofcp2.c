#include <stdio.h>
#include <math.h>
void fn();
int main() 
{
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
        {
        fn();
    }
    return 0;
}
void fn()
    {
    int c,q;
    scanf("%d%d",&c,&q);
    int ar[q][2];
    int i,j;
    for(i=0;i<=q-1;i++)
        {
        for(j=0;j<=1;j++)
            {
            scanf("%d",&ar[i][j]);
        }
    }

    int r1=ar[0][0],r2;
    int d1=0,d2=0,max;
    for(i=0;i<=q-1;i++)
    {
     if(i==0)
     {
        max=abs(ar[0][1]-ar[1][0]);
     }
     else if(i==q-1)
     {
        break;
     }
     else if(i>0)
     {
        if(abs(ar[i][1]-ar[i+1][0])>=max)
        {
            max=abs(ar[i][1]-ar[i+1][0]);
        }
        if(abs(ar[i][1]-ar[i+1][0])<max)
        {
            break;
        }
     }   
    }
    r2=ar[i][0];
    for(i=0;i<=q-1;i++)
        {
            if(abs(r1-ar[i][0])<=abs(r2-ar[i][0]))
                {
                d1=d1+abs(r1-ar[i][0])+abs(ar[i][0]-ar[i][1]);
                r1=ar[i][1];
            }
            else if(abs(r1-ar[i][0])>abs(r2-ar[i][0]))
                {
                d2=d2+abs(r2-ar[i][0])+abs(ar[i][0]-ar[i][1]);
                r2=ar[i][1];
            }
            //printf("%d %d\n",d1,d2);
        }
        printf("%d\n",d1+d2); 
}