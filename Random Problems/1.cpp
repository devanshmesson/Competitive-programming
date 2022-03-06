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

struct node
{
  int val;
  node* next;
  node(int data)
  {
    val=data;
    next=NULL;
  }
};



signed main()
{
  freopen
  ios
  vector<string>s;
  vector<string>z;
  for(int i=0;i<s.size();i++)
  {
    string x=s[i];
    string r = x.substr(0, x.size()-m);
    z.push_back(r);
  }

  vector<int>ans;

  for(int i=0;i<z.size();i++)
  {
    ans.push_back(stoi(z[i]));
  }

  sort(ans.begin(),ans.end());

  vector<int>ret;
  for(int i=0;i<k.size();i++)
  {
    ret.push_back(ans[k[i]-1]);
  }
  return ret;


    
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
