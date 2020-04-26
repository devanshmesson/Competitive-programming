#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       int in,in1,flag=1,f;
       cin>>s;
       int w=s.size();
       for(int i=0;i<w-1;i++)
       {
           if(s[i]!=s[i+1]){flag=0;break;}
       }
       if(flag==1){cout<<s<<endl;continue;}

       if(s[0]=='1')f=1;
       else if(s[0]=='0')f=0;
       int d=1;
       for(int i=0;i<w-1;i++)
       {
          if(f==1)
          {

              if(s[i+1]!='0'){d=0;break;}
              else f=0;

          }
          else if(f==0)
          {
              if(s[i+1]!='1'){d=0;break;}
              else f=1;

          }
       }
       char h;
       int c=0;
       for(int i=0;i<w-1;i++)
       {
           if(s[i]==s[i+1]){c++;}
       }
       w+=c;
       int x;
       if(d==1){cout<<s<<endl;continue;}
       else
       {
           if(s[0]=='1')x=1;
           else if(s[0]=='0')x=0;
           for(int i=0;i<w;i++)
           {
             if(x==1)
             {
                 cout<<1;
                 x=0;
             }
             else if(x==0)
             {
                 cout<<0;
                 x=1;
             }
           }

       }
       cout<<endl;
    }
    return 0;
}
