#include<iostream>
#include<cmath>
using namespace std;
struct Point
{
    int x;
    int y;
};
bool onSegment(Point p, Point q, Point r);
int orientation(Point p, Point q, Point r);
bool doIntersect(Point p1, Point q1, Point p2, Point q2);
void sti(string str,int *a,int *b,int *c,int *d);
int main()
{
	struct Point p1,q1,p2,q2;
	int n;
	cin>>n;
	int a[n][4];
	string str;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		sti(str,&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	for(int i=0;i<n;i++)
		cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
	int count=0;
	for(int i=0;i<n;i++)
	{
		p1.x=a[i][0];
		p1.y=a[i][1];
		q1.x=a[i][2];
		q1.y=a[i][3];
		for(int j=i+1;j<n;j++)
		{
			p2.x=a[j][0];
			p2.y=a[j][1];
			q2.x=a[j][2];
			q2.y=a[j][3];
			if(doIntersect(p1, q1, p2, q2))
			{
				count++;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	if(count==0)
		cout<<0;
	else cout<<2*count-n;
	return 0;
}
void sti(string str,int *a,int *b,int *c,int *d)
{
	int d0=0,co=1,tmp=0;
	for(int i=str.length()-1;i>=0;i--)
	{
		if(str[i]!=',')
		{
			tmp+=(str[i]%48)*pow(10,d0);
			d0++;
		}
		else
		{
			if(co==4)
			{
				*a=tmp;
			}
			else if(co==3)
			{
				*b=tmp;	
			}
			else if(co==2)
			{
				*c=tmp;
			}
			else if(co==1)
			{
				*d=tmp;
			}
			tmp=0;
			d0=0;
			c++;
		}
	}
}
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 	if (o1 != o2 && o3 != o4)
        return true;
 	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}