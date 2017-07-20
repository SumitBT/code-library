#include <stdio.h>
void subarray(int a[], int n, int sub[], int r, int i, int j);
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    int a[n],sub[r];
    int i;
    for(i=0;i<n; ++i)
        scanf("%d", a + i);
    subarray(a, n , sub, r, 0, 0);
}
void subarray(int a[], int n, int sub[], int r, int i, int j)
{
    if(j == r)
    {
        int k;
        printf("( ");
        for(k = 0; k < r; k++)
            printf("%d ", sub[k]);
        printf(")\n");
    }
    else
    {
        if(i < n)
        {
            sub[j] = a[i];
            subarray(a, n, sub, r, i + 1, j + 1); 
            subarray(a, n, sub, r, i + 1, j);  
        }
    }
}