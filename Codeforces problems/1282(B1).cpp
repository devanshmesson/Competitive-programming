#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k,a,bought=0,expense=0,cnt=0,ans=INT_MIN;
        cin>>n>>p>>k;
        vector<int>v;
        for(int i=0;i<n;i++){cin>>a;v.push_back(a);}
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
        {
            expense=bought;
            if(expense>p)break;
            cnt=i;
            for(int j=i+k-1;j<n;j=j+k)
            {
                if(expense+v[j]<=p)
                {
                    expense+=v[j];
                    cnt+=k;
                }
                else break;
            }
            bought+=v[i];
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}
