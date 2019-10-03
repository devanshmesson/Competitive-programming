#include <iostream>
using namespace std;
#define int long long int
main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,flag=1,j=0;
    cin>>n>>k;
    string s;
    cin>>s;
        
        if(n==1 && s[0]!=1 && k!=0){cout<<0<<endl;return 0;}
        if(s[0]!='1' && k!=0){s[0]='1';k=k-1;}
        for(int i=1;i<n;i++){if(s[i]!='0'&& k!=0){if(k==0)break;s[i]='0';k=k-1;}}
         for(int i=0;i<n;i++)cout<<s[i];

}
