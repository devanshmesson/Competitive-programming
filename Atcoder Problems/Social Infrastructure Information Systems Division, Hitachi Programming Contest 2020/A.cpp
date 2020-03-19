#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    string s;
    int c=0,flag=0;
    cin>>s;
    if(s.size()%2!=0){cout<<"No"<<endl;return 0;}
    for(int i=0;i<s.size()-1;i+=2)
    {
        if(s[i]=='h' && s[i+1]=='i')flag=1;
        else {flag=0;break;}
    }
    if(flag==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
