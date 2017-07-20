#include<stdio.h>
#include<stdlib.h>
#define INCORRECT printf("Sentence is incorrect\n")
int main()
{
	int l,i,j;
	char str[100];
	printf("enter sentence\n");
	gets(str);
//	puts(str0);
	l=strlen(str);
//	printf("%d",l);

if(90<str[0] || str[0]<65)  //Sentence must start with uppercase character.
{
	INCORRECT;
	exit(1);
}

if(l==1) //length is 1
{
	INCORRECT;
    exit(2);
}

if(str[l-1]!='.') //last character must be '.'
{
	INCORRECT;
	exit(3);
}
//character before . can be uppercase or lowercase.
{
	if(str[l-2]>122||str[l-2]<65)
	{
		INCORRECT;
		exit(4);
	}
	if(str[l-2]>90 && str[l-2]<97)
	{
		INCORRECT;
		exit(5);
	}
}
//two consecutive spaces are not allowed.
for(i=0;i<=l-1;i++)
{
    if(str[i]==' '&&str[i+1]==' ')
	{
		INCORRECT;
		exit(6);
	}	
}
//two continuos uppercase letters are not allowed.
for(i=0;i<=l-1;i++)
{
	if((65<=str[i]&&str[i]<=90)&&(65<=str[i+1]&&str[i+1]<=90))
	{
		INCORRECT;
		exit(7);
	}
}
//every word must contain lowercase letter after first one.
for(i=0;i<=l-1;i++)
{
    if(str[i]==' ')
	{
		for(j=i+2;str[j]!=' ';j++)
		{
			if(!(str[j]<=122&&str[j]>=97))
			{
				INCORRECT;
				exit(8);
			}
		}
	}	
}
printf("Sentence is correct");
	return 0;
}
