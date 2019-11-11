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
        int n,flag=1,temp,n1,s,cnt=0;
        cin>>n;
        vector<int>v;
        v.push_back(0);
        v.push_back(0);
        n1=n-2;
        s=v.size();
        for(int i=0;i<n1;i++)
        {
           flag=1;
        for(int j=s-2;j>=0;j--)
        {
            if(v[s-1]==v[j]){temp=j;flag=0;break;}
        }
           if(flag==1){s=v.size();v.push_back(0);}
           else if(flag==0){s=v.size();v.push_back(s-1-temp);}
           s=v.size();
        }
        s=v.size();
        //cout<<v.size()<<endl;
        for(int i=0;i<n;i++)
        {
           if(v[n-1]==v[i])cnt++;
        }
        cout<<cnt<<endl;

    }
    return 0;
}
