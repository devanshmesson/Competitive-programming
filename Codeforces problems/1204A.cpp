#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
        string s;
        cin>>s;
        if(s=="0"){cout<<0<<endl;return 0;}
        float sz=s.size(),c=0;
        for(int i=0;i<sz;i++)if(s[i]=='1')c++;
        if(c==1)cout<<ceil((sz-1)/2)<<endl;
        else if(c>1)cout<<ceil(sz/2)<<endl;
}
