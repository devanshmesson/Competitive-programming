#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    int q;
    cin>>q;
    while(q--)
    {
        int  k,x,c=0,d=0,i=0;
        string s;
        cin>>s;
        cin>>k>>x;
        int a[123]={0};
        for(int i=0;i<s.size();i++)
        {
            a[s[i]]++;
            if(a[s[i]]<=x)c++;
            else
            {
                if(k>=1){k--;continue;}
                else break;
            }

        }
        cout<<c<<endl;

    }
    return 0;
}
