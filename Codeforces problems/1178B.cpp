#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int w=0,threshold=0,ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='v' && s[i+1]=='v')
        {
            w++;
            ans+=threshold;
        }
        else if(s[i]=='o')
        {
            threshold+=w;
        }
    }
    cout<<ans<<endl;


    return 0;
}
