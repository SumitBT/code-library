#include<iostream>
using namespace std;
int main(void)
{
    int r,c;
    cin>>r>>c;
    char g[r][c];
    int i,j,di,dj;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='d')
            {
                di=i;
                dj=j;
            }
        }

    return 0;
}
