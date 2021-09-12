#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
 

int main()
{
//   freopen
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int ans=2;

    int zero=0,one=0;
    int last_zero=-1,first_zero=-1;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='1')one=1;
      else 
        {
          if(zero==0)
            {
              first_zero=i;
            }
          zero=1;
          last_zero=i;
        }
    }

    if(zero==1 && one==0){cout<<1<<endl;continue;}
    if(zero==0 && one==1){cout<<0<<endl;continue;}

    if(last_zero==-1){cout<<1<<endl;continue;}
    
    int flag=1;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='1' && i>first_zero && i<last_zero)
      {
        flag=0;
        break;
      }
    }

    if(flag==0){cout<<2<<endl;continue;}
    cout<<1<<endl;
  }
}
