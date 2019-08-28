#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long int n,ans=0,l=1;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
    {
       cin>>s[i];
       sort(s[i].begin(),s[i].end());
    }
    sort(s.begin(),s.end());
     string check=s[0];
    for(int i=1;i<n;i++)
    {
        if(check==s[i]) l++;
        else
        {
            ans+=l*(l-1)/2;
            check=s[i];
            l=1;
        }
    }
    ans+=l*(l-1)/2;
    cout<<ans<<endl;

    return 0;

}
