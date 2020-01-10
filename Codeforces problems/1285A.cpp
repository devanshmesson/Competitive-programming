#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int n,i=0,l=0,r=0,cnt=1;
    cin>>n;
    string s;
    cin>>s;
    while(s[i]!='\0')
    {
        if(s[i]=='L')l++;
        else r++;
        i++;
    }
    cout<<l+r+1<<endl;
 
    return 0;
}
