#include<bits/stdc++.h>
using namespace std;
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
    int x,y,n;
    cin>>x>>y>>n;
    int ans=n%x;
    if(ans==y){cout<<n<<endl;continue;}
    if(ans<y)
    {
      n-=ans;
      n--;
      int minu=x-1-y;
      n-=minu;
      cout<<n<<endl;
    }
    else if(ans>y)
    {
      int minu=ans-y;
      n-=minu;
      cout<<n<<endl;
    }
   }
} 
