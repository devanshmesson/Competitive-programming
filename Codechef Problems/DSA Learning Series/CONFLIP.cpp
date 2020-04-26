#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
    #define endl "\n"
    #define c continue
    int t;
    cin>>t;
    while(t--)
    {
       int n,q,b,a;
       cin>>n;
       for(int i=0;i<n;i++)
       {
          cin>>a>>q>>b;
          if(a==1)
          {
              if((q%2==0)){if(b==1 || b==2)cout<<q/2<<endl;c;}
              else if(q%2!=0 && b==1)
              {
                  cout<<(q/2)<<endl;

              }
              else if(q%2!=0 && b==2)
              {
                  cout<<(q/2)+1<<endl;
              }
            }
            else if(a==2)
            {
              if((q%2==0)){if(b==1 || b==2)cout<<q/2<<endl;}
              else if(q%2!=0 && b==2)
              {
                  cout<<(q/2)<<endl;c;
              }
              else if(q%2!=0 && b==1)
              {
                  cout<<(q/2)+1<<endl;c;
              }
            }
       }

    }
    return 0;
}


