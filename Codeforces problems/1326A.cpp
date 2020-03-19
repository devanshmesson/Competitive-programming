#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int

    int t;
    cin>>t;
    while(t--)
    {
int n;
cin>>n;
if(n==1){cout<<-1<<endl;continue;}

	for(int i=1;i<=n;i++)
    {
        if(i==1)cout<<5;
        else cout<<7;

    }
    cout<<endl;
    }



    return 0;
}
