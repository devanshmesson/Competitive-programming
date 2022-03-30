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
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
  

signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    vector<int>level[n+1];
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<n;i++){cin>>b[i]; level[b[i]].pb(a[i]);}
    priority_queue<int>pq;
    long double sum=0.0;
    long double num=0.0,den=1.0;
    for(int training=0;training<n;training++)
    {
       for(auto x: level[training]){pq.push(x);}
       if(pq.empty())break;
       sum+=pq.top();
       pq.pop();
       if(num*(long double)(training+1)<sum*den)
       {
         num=sum;
         den=training+1;
       }
    }
    cout << fixed << setprecision(8) << num/den << endl;
  }
   
}


/*1.Never overkill a problem.
  2.think of test cases to clarify the approach/doubts.
  3.Don't give up!
  4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
  5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
  6.Check datatype of variables, sometimes wrong datatype lead to WA.
*/ 
