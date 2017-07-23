#include<stdio.h>

int main()
{
  char s1[100],s2[100];
  int i,j,k,l;
  printf("enter string 1");
  gets(s1);
  printf("enter string 2");
   gets(s2);
    for(i=0;s1[i]!='\0';i++)
    {
    for(j=0;s2[j]!='\0';j++)
    {
    if(s1[i]!=' ')
    {
        if(s1[i]==s2[j])
        {
        s2[j]=' ';
        }
       }
   }
   }
   for(i=0;s2[i]!='\0';i++)
   {
    printf("%c",s2[i]);
   }
      return 0;
}
