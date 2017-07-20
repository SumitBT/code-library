#include<stdio.h>
int main()
{
    int r,c,zero[5][5];
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
    return(0);
}
