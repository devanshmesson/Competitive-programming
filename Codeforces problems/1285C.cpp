#include <bits/stdc++.h>
using namespace std;
int main()
{

    #define int long long int
    vector<int>v;
    vector<pair<int,int>>vec;
    int x,ans=1e18,p,q,r;
    cin>>x;

    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
           if(x/i!=i) 
           {
               if(((i*(x/i))/__gcd(i,x/i))==x)
               {
                p=max(i,x/i);
                if(ans>p)
                   {
                     ans=p; q=i; r=x/i;
                   }
               }
           }
           else //checking for perfect square
           {
               if(((i*(i))/__gcd(i,i))==x)
               {
                p=max(i,i);
                if(ans>p)
                   {
                     ans=p; q=i; r=i;
                   }
               }
           }
        }
    }
    cout<<q<<" "<<r<<endl;

    return 0;
}
