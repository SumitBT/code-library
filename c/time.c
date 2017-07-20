#include<stdio.h>
int main()
    {
    char ar[10];
    int i,d1,d2,d3,d;
    scanf("%s",&ar);
    if(ar[8]==80)
        {
        d1=ar[0]-48;
        d2=ar[1]-48;
        d3=10*d1+d2;
        d=d3+12;
        printf("%d",d);
        for(i=2;i<=9;i++)
            {
            printf("%c",ar[i]);
        }
    }
    else if(ar[8]==65)
        {
        for(i=0;i<=7;i++)
            {
        printf("%c",ar[i]);
        }
    }
    return 0;
}
