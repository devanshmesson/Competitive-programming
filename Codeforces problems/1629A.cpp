#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif

#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double

//Kuhn algorithm is used to maximize the pairs that can be matched with each other.
//Pair contains, one vertex from 1st set and 1 vertex from 2nd set.
//One vertex can be matched with only one vertex.


vector<int>man[51];
int mappedto[51];
vector<tuple<int,int,int>>boy,girl;
int visit[51];


signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>v;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){cin>>b[i];v.pb({a[i],b[i]});}
    sort(v.begin(),v.end());

    int ans=0,upd=k;
    for(int i=0;i<v.size();i++)
    {
      if(upd>=v[i].first)
      {
        upd+=v[i].second;
      }
    }

    cout<<upd<<endl;

  }
}
/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
*/ 
