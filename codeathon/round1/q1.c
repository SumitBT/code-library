#include<stdio.h>

int main()

{
  
char str[100];
 
int i;
 
printf("Enter string");

gets(str);
  
for(i=0;str[i]!='\0';i++)
 
{
   
if(str[i]=='a'||str[i]=='A'||str[i]=='e'||str[i]=='E'||str[i]=='i'||str[i]=='I'||str[i]=='o'||str[i]=='O'||str[i]=='u'||str[i]=='U')
 
{
   
str[i]='\0';
   
}
 
}
  
for(i=0;str[i]!='\0';i++)
  
{
  
printf("%c",str[i]);
  
}
 
return 0;

}
