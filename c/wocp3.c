#include <stdio.h>
int main()
    {
    int c,m,n;
    scanf("%d%d%d",&c,&m,&n);
    int v[n][2],i,j,count=0,ind;
    int ar[m];
    for(i=0;i<=m-1;i++)
    	ar[i]=0;
    v[0][0]=c%m;
    v[0][1]=(v[0][0]+c)%m;

    /////////////////////////.SumitBT.////////////////////////

    for(i=1;i<=n-1;i++)
    {
    		v[i][0]=(v[i-1][0]+v[i-1][1])%m;
    		v[i][1]=(v[i-1][1]+v[i][0])%m;
    		if(v[i][0]==v[0][0]&&v[i][1]==v[0][1])
    		{
    			ind=i;
    			break;
    		}
    }

    ///////////////////////////.SumitBT.//////////////////////

    for(i=0;i<=ind-1;i++)
    {
    	for(j=i+1;j<=ind-1;j++)
    	{
    		if(ar[((v[i][0]*v[j][0])+(v[i][1]*v[j][1]))%m]==0)
    		{
    			count++;
    			ar[((v[i][0]*v[j][0])+(v[i][1]*v[j][1]))%m]=-1;
    		}
    		else if(ar[((v[i][0]*v[j][0])+(v[i][1]*v[j][1]))%m]==-1)
    		{
    			continue;
    		}
    	}
    }

    ////////////////////////.SumitBT./////////////////////////

    printf("%d",count);
    return 0;
}