// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

int distancesum(vector<int>arr, int n)
{
    // sorting the array.
    sort(arr.begin(), arr.end());
 
    // for each point, finding the distance.
    int res = 0, sum = 0;
    for (int i = 0; i < n; i++)
     {
        res += (arr[i] * i - sum);
        sum += arr[i];
    }
 
    return res;
}
 
int totaldistancesum(vector<int>x, vector<int>y, int n)
{
    return distancesum(x, n) + distancesum(y, n);
}
 


signed main()
{
  freopen
  ios
  vector<vector<char>>s;
  for(int i=0;i<3;i++)
  {
    vector<int>a;
    for(int j=0;j<3;j++)
    {
      char u;
      cin>>
    }
  }
  int k;

  vector<int>x;
  vector<int>y;

  int row=s[0].size();
  int col=s.size()/row;

  for(int i=0;i<k;i++)
  {
    for(int j=0;j<row;j++)
    {
      if(s[j][i]=='#')
      {
        x.push_back(j);
        y.push_back(i);
      }
    }
  }

  int ans=totaldistancesum(x,y,x.size());
  for(int i=k;i<col;i++)
  {
    x.erase(x.begin());
    y.erase(y.begin());
    for(int j=0;j<row;j++)
    {
      if(s[j][i]=='#')
      {
        x.push_back(j);
        y.push_back(i);
      }
    }
    ans=max(ans,totaldistancesum(x,y,x.size()));
  }
  return ans;

  
    
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
