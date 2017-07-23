#include<stdio.h>
#include<stdlib.h>
int main()
{
   int n=0;
   FILE *fp;
    char ch;
 
    fp=fopen("f.txt","r");
    while(!feof())
    {
     {
       printf("%d",n);
      exit(1);
     }
     n++;
     printf("%c",ch);
    }
  
    fclose(fp);
  return 0;
}
