#include<stdio.h>
int main()
{
    int n,i,array[5];
    int r,c,zero[5][5];
    char string[5],*ptr;
    printf("Enter five digit number\n");
    scanf("%d",&n);
    for(i=4;i>=0;i--)
    {
       array[i]=n%10;
       n=n/10;
    }
    for(i=0;i<=4;i++)
    {
       switch(array[i])
       {
       case 0:
        {
            for(r=0;r<=4;r++)
    {
        for(c=0;c<=4;c++)
        {
            if((r==0&&c==0)||(r==0&&c==4)||(r==1&&c==1)||(r==1&&c==2)||(r==1&&c==3)||(r==2&&c==1)||(r==2&&c==2)||(r==2&&c==3)||(r==3&&c==1)||(r==3&&c==2)||(r==3&&c==3)||(r==4&&c==0)||(r==4&&c==4))
              zero[r][c]=0;
              else
                zero[r][c]=35;
             printf("%c",zero[r][c]);
        }
        printf("\n");
    }
            break;
        }
       case 1:
            {
                printf("%d",1);
                break;
            }
       case 2:
        {
           printf("%d",2);
           break;
        }
       case 3:
        {
            printf("%d",3);
            break;
        }
       case 4:
        {
            printf("%d",4);
            break;
        }
       case 5:
        {
            printf("%d",5);
            break;
        }
       case 6:
        {
            printf("%d",6);
            break;
        }
       case 7:
        {
            printf("%d",7);
            break;
        }
       case 8:
        {
            printf("%d",8);
            break;
        }
       case 9:
        {
            printf("%d",9);
            break;
        }
       }
   }
    return(0);
}
