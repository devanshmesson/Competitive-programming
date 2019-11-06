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
        int n,a,cnt=0,maxm=0;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
 
        for(int i=0;i<n;i++)
        {
          cnt=1;
          for(int j=i+1;j<n;j++)
          {
              if(v[i]<=v[j])
              {
                 cnt++;
              }
          }
          if(cnt>=v[i])
          {
              if(cnt>maxm)
              {
                  maxm=v[i];
              }
          }
          else if(cnt<v[i])
          {
              if(cnt>maxm)
              {
                  maxm=cnt;
              }
          }
        }
        cout<<maxm<<endl;
    }
    return 0;
}
