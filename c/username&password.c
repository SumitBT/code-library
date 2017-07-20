#include<stdio.h>
void inuser(char *p);
void inpass(char *p2);
void inuserc(char *p3);
void inpassc(char *p4);
int main()
{
	int sc=0,c=0,d=0,scc=0,cc=0,dc=0;
	char username[100],password[10],*ptr,*ptr2,checkuser[100],checkpass[10],*ptr3,*ptr4;
	ptr=&username[0];
	ptr2=&password[0];
	ptr3=&checkuser[0];
	ptr4=&checkpass[0];
	inuser(ptr);
	inpass(ptr2);
	while(*ptr!='\0')
	{
		if((*ptr<=90&&*ptr>=65)||(*ptr<=122&&*ptr>=97))
	    {
		    ptr++;
	    }
		else
		{
			printf("invalid username, try again\n");
			ptr=&username[0];
			inuser(ptr);
		}
	}
	if(strlen(ptr2)!=4)
	{
		printf("invalid password, try again\n");
		ptr2=&password[0];
		inpass(ptr2);
	}
	while(*ptr2!='\0')
	{
		if(*ptr2<=57&&*ptr2>=48)
		d++;
		else if((*ptr2<=90&&*ptr2>=65)||(*ptr2<=122&&*ptr2>=97))
		c++;
		else
		sc++;
	}
	if(!(d==1&&sc==2&&c==1))
	{
		printf("invalid password, try again\n");
		ptr2=&password[0];
		inpass(ptr2);
	}
	inuserc(ptr3);
	inpassc(ptr4);
	while(*ptr3!='\0')
	{
		if((*ptr3<=90&&*ptr3>=65)||(*ptr3<=122&&*ptr3>=97))
	    {
		    ptr3++;
	    }
		else
		{
			printf("invalid username, try again\n");
			ptr3=&username[0];
			inuserc(ptr3);
		}
	}
	if(strlen(ptr4)!=4)
	{
		printf("invalid password, try again\n");
		ptr4=&password[0];
		inpassc(ptr4);
	}
	while(*ptr4!='\0')
	{
		if(*ptr4<=57&&*ptr4>=48)
		dc++;
		else if((*ptr4<=90&&*ptr4>=65)||(*ptr4<=122&&*ptr4>=97))
		cc++;
		else
		scc++;
	}
	if(!(dc==1&&scc==2&&cc==1))
	{
		printf("invalid password, try again\n");
		ptr2=&password[0];
		inpassc(ptr2);
	}
	return 0;
}
void inuser(char *p)
{
	printf("enter username\n");
	gets(p);
}
void inpass(char *p2)
{
	printf("enter password\n");
	gets(p2);
}
void inuserc(char *p3)
{
	printf("enter username\n");
	gets(p3);
}
void inpassc(char *p4)
{
	printf("enter password\n");
	gets(p4);
}
