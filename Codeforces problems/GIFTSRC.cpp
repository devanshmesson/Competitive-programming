#include <bits/stdc++.h>
using namespace std;


int main()
{
#define int long long int

    int t;
    cin>>t;
    while(t--)
    {
        int n,x=0,y=0,flag=0;
        cin>>n;
        string s;
        cin>>s;
        if(s[0]=='D' || s[0]=='U')flag=1;
        else if(s[0]=='L' || s[0]=='R')flag=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L' && flag==0)
            {
                flag=1;
                x--;
            }
            else if(s[i]=='R' && flag==0)
            {
               flag=1;
                x++;
            }
            else if(s[i]=='U' && flag==1)
            {
            flag=0;
            y++;
            }
            else if(s[i]=='D' && flag==1)
            {
                flag=0;
                y--;
            }
        }
        cout<<x<<" "<<y<<"\n";

    }
    return 0;
}
