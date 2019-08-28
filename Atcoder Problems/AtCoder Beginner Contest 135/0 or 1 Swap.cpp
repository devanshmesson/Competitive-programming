#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,s,cnt=0;
    cin>>n;
    vector<int> v,h;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        h.push_back(a);
    }
    sort(v.begin(),v.end());

     for(int i=0;i<n;i++)
     {
        if(h[i]!=v[i])
        {
            cnt++;
        }
     }

    if(cnt==2|| cnt==0){cout<<"YES"<<endl;}
    else cout<<"NO"<<endl;
    return 0;
}
