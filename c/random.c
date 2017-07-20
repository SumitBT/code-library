#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int i,count=0,e;
	srand(time(NULL));
	int n=rand()%1000;
	for(i=1;i<=10;i++)
        {
           printf("Enter your attempt no.%d\n",i);
           scanf("%d",&e);
           if(e==-1)
           {
           	i--;
           	printf("%d\n",n);
           	continue;
           }
           if(e==-2)
           {
           	i--;
           	system("cls");
           	continue;
           }
           if(e<n)
           {
               printf("This number is less than the answer\n"); 
           }
           if(e>n)
           {
              printf("This number is greater than the answer\n");
           }
           if(e==n)
           {
               printf("Congratulations you won...! Points = %d\n",11-i);
               count++;
               break;
           }
        }
        if(count==0)
        {
            printf("You lost........! Points = 0\n");
        }
        return 0;
}
