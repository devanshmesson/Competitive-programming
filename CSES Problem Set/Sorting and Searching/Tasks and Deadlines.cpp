/*
Question -Given Duration and Deadline.Reward for completing a task is (Deadline-Finishing time).Calculate maxmimum reward.
Solved - O(nlog(n)) Time Complexity
Approach-Sort the durations and calculate the reward(because we have to complete the task as soon as possible to get maximum reward).
*/
#include<bits/stdc++.h>
using namespace std;

main()
{
  int n,a,b;
  cin>>n;
  vector<pair<int,int>>v;
  for(int i=0;i<n;i++)
  {
   cin>>a>>b;
   v.push_back({a,b});
  }
  sort(v.begin(),v.end());
  int ans=0;
  for(int i=0;i<n;i++)
  {
    ans+=v[i].second-v[i].first;
    v[i+1].first+=v[i].first;
  }
  cout<<ans<<endl;


}
