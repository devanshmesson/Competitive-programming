#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,a,s=0,cnt=0,k=0;
        cin>>n;
        vector<int> v,h;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
          cnt=0;
          for(int j=i+1;j<n;j++)
          {
              if(v[j]>v[i])cnt++;
          }
          h.push_back(cnt);
        }

 for(int i=0;i<n;i++)
 {
     cout<<h[i]<<" ";
 }
 cout<<endl;
    }

    return 0;
}
