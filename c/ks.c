#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp=fopen("New.c","r");
	char ch;
	while(1)
	{
	ch=getc(fp);
        if(ch==NULL)
{
printf("f");
fclose(fp);
exit(1);
}
	if(ch=='\n')
	{
		while(ch!='\n')
		{
			ch=fgetc(fp);
			printf("%c",ch);
			fp++;
		}
fclose(fp);
		exit(1);
    }
    else
          fp++;
    }
    fclose(fp);
    return 0;
}