#include<stdio.h>
#include<stdlib.h>
#define W printf("You won the game");
int main()
{
	int i,j,k,c;
	char ar[13][13]={
	                  201,205,205,205,203,205,205,205,203,205,205,205,187,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  204,205,205,205,206,205,205,205,206,205,205,205,185,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  204,205,205,205,206,205,205,205,206,205,205,205,185,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  186,0,0,0,186,0,0,0,186,0,0,0,186,
	                  200,205,205,205,202,205,205,205,202,205,205,205,188
	                };
	                for(i=0;i<=12;i++)
	                {
	                	for(j=0;j<=12;j++)
	                	{
	                		printf("%c",ar[i][j]);
	                	}
	                	printf("\n");
	                }
	                for(k=1;k<=9;k++)
	                {
	                	printf("Enter choice\n");
	                	scanf("%d",&c);
	                	if(k%2==1)
	                	{
	                		if(c==1)
	                		ar[2][2]=35;
	                		if(c==2)
	                		ar[2][6]=35;
	                		if(c==3)
	                		ar[2][10]=35;
	                		if(c==4)
	                		ar[6][2]=35;
	                		if(c==5)
	                		ar[6][6]=35;
	                		if(c==6)
	                		ar[6][10]=35;
	                		if(c==7)
	                		ar[10][2]=35;
	                		if(c==8)
	                		ar[10][6]=35;
	                		if(c==9)
	                		ar[10][10]=35;
	                	}
	                	if(k%2==0)
	                	{
	                		if(c==1)
	                		ar[2][2]=79;
	                		if(c==2)
	                		ar[2][6]=79;
	                		if(c==3)
	                		ar[2][10]=79;
	                		if(c==4)
	                		ar[6][2]=79;
	                		if(c==5)
	                		ar[6][6]=79;
	                		if(c==6)
	                		ar[6][10]=79;
	                		if(c==7)
	                		ar[10][2]=79;
	                		if(c==8)
	                		ar[10][6]=79;
	                		if(c==9)
	                		ar[10][10]=79;
	                	}
	                	for(i=0;i<=12;i++)
	                {
	                	for(j=0;j<=12;j++)
	                	{
	                		printf("%c",ar[i][j]);
	                	}
	                	printf("\n");
	                }
	                if(k>4)
	                {
	                if(ar[2][2]==ar[2][6]&&ar[2][6]==ar[2][10]&&ar[2][2]!=0&&ar[2][6]!=0&&ar[2][10]!=0)
	                {
	                W;
					exit(1);
				    }
	                if(ar[2][2]==ar[6][2]&&ar[6][2]==ar[10][2]&&ar[2][2]!=0&&ar[6][2]!=0&&ar[10][2]!=0)
	                {
	                W;
					exit(2);
				    }
	                if(ar[2][2]==ar[6][6]&&ar[6][6]==ar[10][10]&&ar[2][2]!=0&&ar[6][6]!=0&&ar[10][10]!=0)
	                {
	                W;
					exit(3);
				    }
	                if(ar[10][2]==ar[10][6]&&ar[10][6]==ar[10][10]&&ar[10][2]!=0&&ar[10][6]!=0&&ar[10][10]!=0)
	                {
	                W;
					exit(4);
				    }
	                if(ar[10][2]==ar[6][6]&&ar[6][6]==ar[2][10]&&ar[10][2]!=0&&ar[6][6]!=0&&ar[10][2]!=0)
	                {
	                W;
					exit(5);
				    }
					if(ar[2][10]==ar[6][10]&&ar[6][10]==ar[10][10]&&ar[2][10]!=0&&ar[6][10]!=0&&ar[10][10]!=0)
	                {
	                W;
					exit(6);
				    }
				    if(ar[6][2]==ar[6][6]&&ar[6][6]==ar[6][10]&&ar[6][2]!=0&&ar[6][6]!=0&&ar[6][10]!=0)
	                {
	                W;
					exit(6);
				    }
				    if(ar[2][6]==ar[6][6]&&ar[6][6]==ar[10][6]&&ar[2][6]!=0&&ar[6][6]!=0&&ar[10][61]!=0)
	                {
	                W;
					exit(6);
				    }
	            }
	            }
				if(k>4)
	                {
	                if(ar[2][2]==ar[2][6]&&ar[2][6]==ar[2][10]&&ar[2][2]!=0&&ar[2][6]!=0&&ar[2][10]!=0)
	                {
	                W;
					exit(1);
				    }
	                if(ar[2][2]==ar[6][2]&&ar[6][2]==ar[10][2]&&ar[2][2]!=0&&ar[6][2]!=0&&ar[10][2]!=0)
	                {
	                W;
					exit(2);
				    }
	                if(ar[2][2]==ar[6][6]&&ar[6][6]==ar[10][10]&&ar[2][2]!=0&&ar[6][6]!=0&&ar[10][10]!=0)
	                {
	                W;
					exit(3);
				    }
	                if(ar[10][2]==ar[10][6]&&ar[10][6]==ar[10][10]&&ar[10][2]!=0&&ar[10][6]!=0&&ar[10][10]!=0)
	                {
	                W;
					exit(4);
				    }
	                if(ar[10][2]==ar[6][6]&&ar[6][6]==ar[2][10]&&ar[10][2]!=0&&ar[6][6]!=0&&ar[10][2]!=0)
	                {
	                W;
					exit(5);
				    }
					if(ar[2][10]==ar[6][10]&&ar[6][10]==ar[10][10]&&ar[2][10]!=0&&ar[6][10]!=0&&ar[10][10]!=0)
	                {
	                W;
					exit(6);
				    }
				    if(ar[6][2]==ar[6][6]&&ar[6][6]==ar[6][10]&&ar[6][2]!=0&&ar[6][6]!=0&&ar[6][10]!=0)
	                {
	                W;
					exit(6);
				    }
				    if(ar[2][6]==ar[6][6]&&ar[6][6]==ar[10][6]&&ar[2][6]!=0&&ar[6][6]!=0&&ar[10][61]!=0)
	                {
	                W;
					exit(6);
				    }
	            }
	return 0;
}