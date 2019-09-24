//Shooting
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long int a,n,sum=0,ans=0;
    cin>>n;
    vector<int> v,h;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        h.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n;i++)
    {
        ans=v[i]*(i)+1;
        sum=sum+ans;
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
 
                if(v[i]==h[j])
                {
                    cout<<j+1<<" ";
                    h[j]=0;
                    break;
                }
        }
    }
    return 0;
}
