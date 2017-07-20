#include<stdio.h>
int main(void)
{
    int r,l,R,i;
    scanf("%d",&r);
    char str[501];
    char last,flag;
    for(R=1;R<=r;R++)
    {
        scanf("%d",&l);
        scanf("%s",&str);
        flag='f';
        last='T';
        for(i=0;i<l;i++)
        {
            if(str[i]=='T')
            {
                if(last=='T')
                {
                    printf("Invalid\n");
                    flag='t';
                    break;
                }
                last='T';
            }
            else if(str[i]=='H')
            {
                if(last=='H'||i==l-1)
                {
                    printf("Invalid\n");
                    flag='t';
                    break;
                }
                last='H';
            }
        }
        if(flag=='f')
        {
            printf("Valid\n");
        }
    }
    return 0;
}
