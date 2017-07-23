#include<iostream>
using namespace std;
bool found=false;
char fn1(int);
int fn(int);
int main(void)
{

    string str;
    cin>>str;
    char ch;
    cin>>ch;
    int i,j,l=0;
    char a[8][8];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            a[i][j]='*';
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;)
        {
            if(str[l]=='/')
                l++;
            else switch(str[l++])
            {
            case '1':
                j++;
                break;
            case '2':
                j+=2;
                break;
            case '3':
                j+=3;
                break;
            case '4':
                j+=4;
                break;
            case '5':
                j+=5;
                break;
            case '6':
                j+=6;
                break;
            case '7':
                j+=7;
                break;
            case '8':
                j+=8;
                break;
            case 'r':
                a[i][j++]='r';
                break;
            case 'n':
                a[i][j++]='n';
                break;
            case 'b':
                a[i][j++]='b';
                break;
            case 'q':
                a[i][j++]='q';
                break;
            case 'k':
                a[i][j++]='k';
                break;
            case 'p':
                a[i][j++]='p';
                break;
            case 'R':
                a[i][j++]='R';
                break;
            case 'N':
                a[i][j++]='N';
                break;
            case 'B':
                a[i][j++]='B';
                break;
            case 'Q':
                a[i][j++]='Q';
                break;
            case 'K':
                a[i][j++]='K';
                break;
            case 'P':
                a[i][j++]='P';
                break;
            }
        }
    }
    int ip1=-1,jp1=-1,ip2=-1,jp2=-1;
    int ic,jc,ik,jk;
    cout<<"[";
    if(ch=='w')
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
               if(a[i][j]=='N')
               {
                   if(ip1==-1&&jp1==-1)
                    {
                        ip1=i;jp1=j;
                    }
                   else
                   {
                       ip2=i;jp2=j;
                       break;
                   }
               }
            }
        }
        if(ip1!=-1&&jp1!=-1)
        {
            ic=ip1;jc=jp1;
            ik=ic-2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc-2;;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc-2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
        }
        if(ip2!=-1&&jp2!=-1)
        {
            ic=ip2;jc=jp2;
            ik=ic-2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc-2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc-2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=97&&a[ik][jk]<=122)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
        }
    }
    else
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
               if(a[i][j]=='n')
               {
                   if(ip1==-1&&jp1==-1)
                    {
                        ip1=i;jp1=j;
                    }
                   else
                   {
                       ip2=i;jp2=j;
                       break;
                   }
               }
            }
        }
        if(ip1!=-1&&jp1!=-1)
        {
            ic=ip1;jc=jp1;
            ik=ic-2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc-2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc-2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
        }
        if(ip2!=-1&&jp2!=-1)
        {
            ic=ip2;jc=jp2;
            ik=ic-2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc+2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc+1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic+1;jk=jc-2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-1;jk=jc-2;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
            ik=ic-2;jk=jc-1;
            if((ik>=0&&ik<=7)&&(jk>=0&&jk<=7)&&((a[ik][jk]>=65&&a[ik][jk]<=90)||a[ik][jk]=='*'))
                cout<<fn1(jc)<<fn(ic)<<fn1(jk)<<fn(ik)<<",";
        }
    }
    if(found==true)
        cout<<"\b";
    cout<<"]";
    return 0;
}
char fn1(int k)
{
    found=true;
    switch(k+97)
    {
    case 97:
        return 'a';
    case 98:
        return 'b';
    case 99:
        return 'c';
    case 100:
        return 'd';
    case 101:
        return 'e';
    case 102:
        return 'f';
    case 103:
        return 'g';
    case 104:
        return 'h';
    }
}
int fn(int k)
{
    switch(k)
    {
    case 0:
        return 8;
    case 1:
        return 7;
    case 2:
        return 6;
    case 3:
        return 5;
    case 4:
        return 4;
    case 5:
        return 3;
    case 6:
        return 2;
    case 7:
        return 1;
    }
}
