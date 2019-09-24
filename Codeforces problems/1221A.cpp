//2048 Game
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,a,flag=0;
        cin>>n;
        vector<long long int> v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
 
        for(int i=0;i<n;i++)
        {
            if(v[i]==2048){cout<<"YES"<<endl; flag=1; break;}
        }
        if(flag==1)continue;
        else
        {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sort(v.begin(),v.end());
                if(i!=j)
                {
                    if(v[i]==v[j])
                    {
                        v[i]=v[i]+v[j];
                        v[j]=0;
                        if(v[i]==2048){flag=1;break;}
 
 
                    }
 
                }
 
 
            }
            if(flag==1)break;
        }
        }
       if(flag==1){cout<<"YES"<<endl;continue;}
        else{cout<<"NO"<<endl;}
    }
    return 0;
}
