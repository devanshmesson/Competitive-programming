/*
Problem-Find Smaller element which is nearest to current position of element of array
Time Complexity-O(n)
Approach-Used Stack
        -Check if top < a[i] , if not then keep popping elements till the condition satisfies 
        -Push the current element and repeat the steps
*/
include<bits/stdc++.h>
using namespace std;
main() 
{
  int n;
  cin>>n;
  int a[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  stack<pair<int,int>>s;
  s.push({a[0],1});
  cout<<0<<" ";
  bool flag=0;
  for(int i=1;i<n;i++)
  {
      flag=0;
      if(s.top().first<a[i] && !s.empty())
      {
        cout<<s.top().second<<" ";
      }
      else if(s.top().first>=a[i])
      {
        while(1)
        {
            s.pop();
            if(s.empty()){flag=1;cout<<0<<" ";break;}
            if(s.top().first<a[i]){cout<<s.top().second<<" ";break;}
        }
      }
      else {cout<<0<<" ";}
      s.push({a[i],i+1});
  }  
}
