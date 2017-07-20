#include<stdio.h>
int main()
{
int yr,byr=1900,lp,rem,td,day;
printf("Enter year:");
scanf("%d",&yr);
yr=(yr-1)-byr;
lp=yr/4;
rem=yr-lp;
td=(rem*365)+(lp*366)+1;
day=td%7;
if (day==0)
    printf("Monday");
else if (day==1)
    printf("Tuesday");
else if (day==2)
    printf("Wednesday");
else if (day==3)
    printf("Thursday");
else if (day==4)
    printf("Friday");
else if (day==5)
    printf("Saturday");
else if (day==6)
    printf("Sunday");
    return 0;
}
