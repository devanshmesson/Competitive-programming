#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool customsort(const pair<int,int>&a,const pair<int,int>&b)
{
  if(a.first==b.first)
  {
    return a.second>b.second;
  }
  return a.first<b.first;
}
#define pb push_back
main() 
{
   int t;
   cin>>t;
   while(t--)
   {  
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
  
    map<int,int>mp;
 
    for(int i=0;i<=30;i++)  //Finding which bit is set(1) for all array elements
    {                       //For ex: in array 2 3 4 5 10 
      for(int j=0;j<n;j++)  //0th bit is set for 3,5 ; 1st bit is set for 10,3,2 
      {                     //2nd bit set for 4,5    ; 3rd bit is set for 10
       int ch=(1<<i);
        if((ch & a[j])==ch)
          {
             mp[i]++;   //Counting the ith set bit in all array elements
          }

      }
    }     
    vector<int>lft;
    for(int i=0;i<=30;i++)
    {
      if(mp[i]==0)lft.pb(i);  //storing ith bit which is not set in any array element
    }
    sort(lft.begin(),lft.end()); //sorting for minimizing the answer
    
    vector<pair<int,int>>v;     
    for(auto x:mp)
    {
      if(x.second!=0)v.pb({x.second*(1<<x.first),x.first});  //storing sum of all common set bits 
    }                                                        //in all array elements
    sort(v.begin(),v.end(),customsort);                      //sorting in decreasing order
    int ans=0,stop=0,flag=1,mxa=INT_MIN;
    for(int i=v.size()-1;i>=0;i--)           //Accessing from last to achieve maximum sum possible
    {
      ans+=(1<<v[i].second);
      stop++;
      if(stop==k){flag=0;break;}    //break if we included k bits in the answer
    }
    if(flag) // if less than k bits are included then we pick the unset bits in the lft vector
    {
      flag=1;
      for(int i=0;i<lft.size();i++)
      {
        ans+=(1<<lft[i]);   
        stop++;
        if(stop==k){flag=0;break;}
      }
    }
    cout<<ans<<endl;
   }   
}
