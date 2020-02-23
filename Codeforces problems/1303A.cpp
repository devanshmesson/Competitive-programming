#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    #define int long long int
    int t;
    cin>>t;
    while(t--)
    {
        string s;
       bool flag=0;
        int cnt=0,t=0;
        cin>>s;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                flag=1;
                int j=i+1;
                int te=0;
                while(s[j]=='0' && j<s.size())
                {
                    if(s[j]=='0'){cnt++;te++;}
                    if(s[j]=='1'){flag=0;break;}
                    if(j==s.size()-1 && s[j]!='1')cnt-=te;
                    j++;
                }

            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
