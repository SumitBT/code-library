#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
    int T;
    cin>>T;
    int n,m,a[500][500],i,j,min,max,in[250000][2],ax[250000][2],k,l,mind,maxd;
    for(int t=1;t<=T;t++)
    {
        min=1000001;max=0;
        cin>>n>>m;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]<min)
                    min=a[i][j];
                if(a[i][j]>max)
                    max=a[i][j];
            }
        k=0;l=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(a[i][j]==min)
                {
                    in[k][0]=i;
                    in[k][1]=j;
                    k++;
                }
                if(a[i][j]==max)
                {
                    ax[l][0]=i;
                    ax[l][1]=j;
                    l++;
                }
            }

        for(i=0;i<k;i++)
        {
            mind=abs(in[i][0]-ax[0][0])>=abs(in[i][1]-ax[0][1])?abs(in[i][0]-ax[0][0]):abs(in[i][1]-ax[0][1]);
            for(j=1;j<l;j++)
            {
                if(mind>(abs(in[i][0]-ax[j][0])>=abs(in[i][1]-ax[j][1])?abs(in[i][0]-ax[j][0]):abs(in[i][1]-ax[j][1])))
                    mind=(abs(in[i][0]-ax[j][0])>=abs(in[i][1]-ax[j][1])?abs(in[i][0]-ax[j][0]):abs(in[i][1]-ax[j][1]));
            }
            if(i==0)
                maxd=mind;
            else if(mind>maxd)
                maxd=mind;
        }
        cout<<maxd<<endl;
    }
    return 0;
}
