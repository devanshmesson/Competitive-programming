#include <bits/stdc++.h>
using namespace std;
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a;
    cin>>n;
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        a=s[i];
        a+=n;
        if(a>90){a=a-90;a+=64;}
        char c=char(a);
        cout<<c;
    }
}









