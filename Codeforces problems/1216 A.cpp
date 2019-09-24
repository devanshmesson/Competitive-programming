//Prefixes
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,i=0,cnt=0,c=0,d1,d2,ans=0,flag=1;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i=i+2)
    {
        if(s[i]=='a'&& s[i+1]=='a') {s[i]='b'; cnt++;}
        else if(s[i]=='b'&& s[i+1]=='b'){s[i]='a';cnt++;}
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }
    return 0;
}
