#include<bits/stdc++.h>
using namespace std;
long int mod=1000000000;
#define int long long int
string s;
int cb[2010]={0};int x=1,y=1,flag=0;

int evaluate(int l,int r,int a)
    {

    for(int i=l;i<=r;i++)
    {

        if(s[i]=='N' || s[i]=='W' || s[i]=='E' || s[i]=='S')
        {


            if(s[i]=='N')
            {
                //cout<<"s[i]=='N'"<<endl;
                x-=a;
                //cout<<"x="<<x<<endl;
                if(x<=0)x+=mod;
                else if(x!=mod)x=x%mod;
                //cout<<"after mod x="<<x<<endl;
            }
            else if(s[i]=='S')
            {
                //cout<<"s[i]=='S'"<<endl;
                x+=a;
                //cout<<"x="<<x<<endl;
                if(x<=0)x+=mod;
               else if(x!=mod)x=x%mod;
                //cout<<"after mod x="<<x<<endl;
            }
            else if(s[i]=='W')
            {
                //cout<<"s[i]=='W'"<<endl;
                y-=a;
                //cout<<"y="<<y<<endl;
                if(y<=0)y+=mod;
                else if(y!=mod)y=y%mod;
                //cout<<"after mod y="<<y<<endl;
            }
            else if(s[i]=='E')
            {
                //cout<<"s[i]=='E'"<<endl;
                y+=a;
                //cout<<"y="<<y<<endl;
                if(y<=0)y+=mod;
                else if(y!=mod)y=y%mod;
                //cout<<"after mod y="<<y<<endl;
            }

        }
        else if(isdigit(s[i]))
        {
            a*=s[i]-'0';
            flag=1;
          //cout<<"before i="<<i<<endl;
          evaluate(i+2,cb[i+1]-1,a);
          //cout<<"after i="<<i<<endl;
          a/=s[i]-'0';

          i=cb[i+1];
        }

    }

    }
main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    #define pb push_back
    #define mk make_pair

    int n;
    cin>>n;
    for(int v=1;v<=n;v++)
    {

    cin>>s;
    vector<int>k;
    stack<pair<char,int>>p;
    int h=s.size();
    int d=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('){p.push({s[i],i});k.push_back(i);}
        if(s[i]==')')
        {
            if(p.top().first=='('){cb[p.top().second]=i;p.pop();d++;}
        }
    }
    evaluate(0,h-1,1);
    cout<<"Case #"<<v<<": "<<y<<" "<<x<<endl;
    s.clear();
    x=1;y=1;
    fill_n(cb,2010, 0);
    }








    return 0;
}
