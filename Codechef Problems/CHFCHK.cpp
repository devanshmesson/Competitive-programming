#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
      int na,a;
      cin>>na;
      vector<int>j;
      for(int i=0;i<na;i++)
      {
          cin>>a;j.push_back(a);
      }
      sort(j.begin(),j.end());
      cout<<j[0]<<endl;
    }
    return 0;
}
