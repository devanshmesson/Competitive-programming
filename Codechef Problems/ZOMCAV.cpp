#include <bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
         int t;
         cin>>t;
         while(t--)
         {
        int n,a,b,flag=0,high=0,low=0;
        cin>>n;
        vector<int> v,h,r;
        for(int i=0;i<n;i++)
        {
            a=0;
            r.push_back(a);
           // cout<<r[i]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        for(int k=0;k<n;k++)
        {
            cin>>b;
            h.push_back(b);
        }
        for(int i=0;i<n;i++)
        {
           low=max(0,i-v[i]);
            r[low]+=1;
            high=min(n-1,i+v[i]);
            r[high+1]-=1;
        }

        for(int j=1;j<=n;j++) r[j]=r[j]+r[j-1];
          sort(r.begin(),r.end());
          sort(h.begin(),h.end());
      for(int i=0;i<n;i++)
        {
            if(r[i]!=h[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
         }


    return 0;
}
