#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long int,long long int> &a,const pair<long long int,long long int> &b)
{
    return (a.second<b.second);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   long long int n,cnt=1,a,b,k=0;
   cin>>n;
   vector< pair <long long int,long long int> > v;
   for(int i=0;i<n;i++)
   {
       cin>>a>>b;
       v.push_back(make_pair(a,b));
   }
   sort(v.begin(),v.end(),sortbysec);

   for(int i=1;i<n;i++)
   {
       if(v[i].first>=v[k].second)
       {
           cnt++;
           k=i;
       }
   }
   cout<<cnt;

    return 0;
}
