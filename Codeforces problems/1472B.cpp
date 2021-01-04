#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define endl "\n"
int main()
{
    io
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
      int n,a;
      cin>>n;
      int one=0,two=0;
      for(int i=0;i<n;i++)
      {
        cin>>a;
        if(a==2)two++;
        if(a==1)one++;
      }
      int sum=(two*2+one),var;
      if(sum%2==1){cout<<"NO"<<endl;continue;}
 
      int target=sum/2;
 
      if(target%2==0 || (target%2==1 && one>0))cout<<"YES"<<endl;
      else cout<<"NO"<<endl;  
    }
}
