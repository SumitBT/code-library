#include<stdio.h>
int s=0;
void main()
{
int i;
system("cls");

for(i=0;i<=s;i++)
{
	printf(" ");
}
printf("       **   **\n");

for(i=0;i<=s;i++)
{
	printf(" ");
}
printf("      *  * *  *\n");

for(i=0;i<=s;i++)
{
	printf(" ");
}
printf("     *    *    *\n");

printf("Ravi ");
for(i=0;i<=s;i++)
{
	printf(" ");
}
printf(" * LOVE  *");
for(i=0;i<=61-s-13;i++)
{
	printf(" ");
}
printf("Anita\n");
for(i=0;i<=s;i++)
{
	printf(" ");
}
printf("       *     *\n");
for(i=0;i<=s;i++)
{
	printf(" ");
}
printf("        *   *\n");
for(i=0;i<=s;i++)
{
	printf(" ");
}
printf("         * *\n");
for(i=0;i<=s;i++)
{
	printf(" ");
}
printf("          *\n");
s++;
if(s<50)
main();
}
