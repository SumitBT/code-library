#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][2],i,j,count=0;
	for(i=0;i<n;i++)
		cin>>a[i][0];
	for(i=0;i<n;i++)
		a[i][1]=0;
	i=0;j=n-1;
	while(i<j)
	{
		if(a[i][0]==a[j][0])
		{
			a[i][1]=1;
			a[j][1]=1;
			i++;
			j--;
		}
		else
		{
			if(a[i][0]<a[j][0])
			{
				a[i+1][0]+=a[i][0];
				i++;
				count++;
			}
			else
			{
				a[j-1][0]+=a[j][0];
				j--;
				count++;
			}
		}
	}
	if(i==j)
		a[i][1]=1;
	if(count==n-1)
		cout<<"TRIVIAL MERGE";
	else
	{
		cout<<count<<endl;
		for(i=0;i<n;i++)
			if(a[i][1]==1)
				cout<<a[i][0]<<" ";
	}
	return 0;
}