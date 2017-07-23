#include<stdio.h>
#define INCORRECT printf("Sentence is incorrect\n")
int main()
{
char str[100];
int i,l;
printf("Enter Sentence\n");
gets(str);
l=strlen(str);
//printf("%d",l);

//condition for length 1

if(l==1)
{
printf("one character can't form a sentence\n");
INCORRECT;
exit(1);
}

//condition for length 2

if(l==2)
{
if((!(65<=str[0]<=90))||(str[1]!='.'))
{
INCORRECT;
exit(2);
}
}

//condition for length more than 2

if(!(65<=str[0]<=90))
{
INCORRECT;
exit(3);
}

for(i=1;i<=l-1;i++)
{
if(str[i]!=' ')
{
 if(!(97<=str[i]<=122))
 {
 INCORRECT;
 exit(4);
 }
 }
}

if(str[l-1]!='.')
{
INCORRECT;
exit(3);
}

for(i=0;i<=l-1;i++)
{
if(str[i]==' ')
{
if(str[i+1]==' ')
{
INCORRECT;
exit(4);
}
}
}

for(i=0;i<=l-1;i++)
{
if(65<=str[i]<=90)
{
if(65<=str[i+1]<=90)
{
INCORRECT;
exit(4);
}
}
}

if(65<=str[l-2]<=90)
{
printf("Sentence is correct\n");
}
printf("Sentence is correct\n");
return 0;
}
