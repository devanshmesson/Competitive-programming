/*
Question - Finding a triplet which sums to a given value(x)
Solved - O(n^2) Time-Complexity
Approach-Sort the array.
        -There will be two nested loops 
        -First loop will decide the first element of the triplet and second loop will find if there is pair exists which sums to (x-first value of triplet)
*/
#include<bits/stdc++.h>
 using namespace std;
main() 
{
  int n,x,z;
  cin>>n>>x;
  vector<pair<int,int>>a;
  for(int i=0;i<n;i++){cin>>z;a.push_back({z,i});}
  sort(a.begin(),a.end());
  int flag=1;
  int low=1,high=n-1,b,c,d;
  for(int i=0;i<n;i++)
  {
    low=i+1; high=n-1;
    while(low<high)
    {
      if(a[low].first+a[high].first==(x-a[i].first)){b=a[i].second+1;c=a[low].second+1;d=a[high].second+1;flag=0;break;}
      else if(a[low].first+a[high].first>(x-a[i].first))high--;
      else if(a[low].first+a[high].first<(x-a[i].first))low++;
    }
  }
  if(flag==0)cout<<b<<" "<<c<<" "<<d<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}
