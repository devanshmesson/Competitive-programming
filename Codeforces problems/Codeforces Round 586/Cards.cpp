#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long int n,i=0,cnt=0,c=0;
    string s;
    cin>>n;
    cin>>s;
    while(s[i]!='\0')
    {
        if(s[i]=='n')cnt++;
        else if(s[i]=='z')c++;
        i++;
    }
    for(int i=0;i<cnt;i++)
    {
        cout<<"1"<<" ";
    }
    for(int i=0;i<c;i++)
    {
        cout<<"0"<<" ";
    }
    return 0;
}
