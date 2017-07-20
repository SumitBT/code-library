/*
2. An m x n matrix is said to have a saddle point if some entry a[i][j]
is the smallest value in row i and the largest value in j. Write C/ C++
function that determines the location of a saddle point if one exists.
*/
#include<iostream>
using namespace std;
int main(void)
{
    int r,c;
    cout<<"Enter number of rows and columns\n";
    cin>>r>>c;
    int a[r][c],i,j,k;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int min_i,min_i_c,max_j;
    bool FOUND=false;
    for(i=0;i<r;i++)
    {
        min_i=a[i][0];
        min_i_c=0;
        for(j=1;j<c;j++)
        {
            if(a[i][j]<min_i)
            {
                min_i=a[i][j];
                min_i_c=j;
            }
        }
        max_j=a[0][min_i_c];
        for(k=1;k<r;k++)
        {
            if(a[k][min_i_c]>max_j)
                max_j=a[k][min_i_c];
        }
        if(min_i==max_j)
        {
            FOUND=true;
            cout<<"saddle point foud : a["<<i<<"]["<<min_i_c<<"]= "<<min_i;
            break;
        }
    }
    if(FOUND==false)
        cout<<"saddle point not found\n";
    return 0;
}
//Author:SUMITBT
