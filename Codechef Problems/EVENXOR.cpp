// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif

#define pb push_back
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

void makeCombiUtil(vector<vector<int> >& ans, vector<int>& tmp, int n, int left, int k)
{
  if (k == 0) {
    ans.push_back(tmp);
    return;
  }
  for (int i = left; i <= n; ++i)
  {
    tmp.push_back(i);
    makeCombiUtil(ans, tmp, n, i + 1, k - 1);
    tmp.pop_back();
  }
}

vector<vector<int> > makeCombi(int n, int k)
{
  vector<vector<int> > ans;
  vector<int> tmp;
  makeCombiUtil(ans, tmp, n, 1, k);
  return ans;
}

// Driver code
signed main()
{
  freopen
  ios
  vector<vector<int> > ans = makeCombi(19, 4);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int res=0;
   

   for (int i = 0; i < n; i++) 
   {
    res=0;
    for (int j = 0; j < ans[i].size(); j++) 
    {
       int bit=ans.at(i).at(j);
       bit--;
       res=(1<<bit)|res;
    }
    cout<<res<<" ";
   }
   cout<<endl;

  }

}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
*/ 
