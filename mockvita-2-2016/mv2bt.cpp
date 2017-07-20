#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(void)
{
    int n,f,b,t,fd,bd;
    cin>>n;
    for(int c=1;c<=n;c++)
    {
        cin>>f>>b>>t>>fd>>bd;
        bool ditched=false;
        int d=0,tt=0;
        if(f==b&&fd>=f&&bd>=b)
        {
            cout<<"No Ditch\n";
            ditched=true;
        }
        if(f>=b&&ditched==false)
        {
            int nf;
            nf=f*(fd/f);
            d=(f-b)*(nf/(f-b));
            tt=t*(nf/(f-b))*(f+b);
            //cout<<d<<" "<<tt;
            while(!ditched)
            {
                if(fd<=d+f)
                {
                    tt+=(fd-d)*t;
                    cout<<tt<<" "<<"F"<<endl;
                    ditched=true;
                }
                d+=f-b;
                tt+=(f+b)*t;
            }
        }
        else if(ditched==false)
        {
             while(!ditched)
            {
                if(bd<=d+(b-f))
                {
                    tt+=2*f*t;
                    tt+=(bd-d)*t;
                    cout<<tt<<" "<<"B"<<endl;
                    ditched=true;
                }
                d+=b-f;
                tt+=(f+b)*t;
            }
        }
    }
    return 0;
}
