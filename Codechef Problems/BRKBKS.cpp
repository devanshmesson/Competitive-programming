#include <bits/stdc++.h>

using namespace std;

int main()
{
    #define int long long int
    ios::sync_with_stdio();cin.tie();cout.tie();
    int t;
    cin>>t;
    while(t--)
    {
        int s,g,b,c,cnt=0;
        int a[10];
        cin>>s>>g>>b>>c;
        a[0]=g;
        a[1]=b;
        a[2]=c;
        //sort(a,a+3,greater<int>());

            if(a[0]+a[1]+a[2]<=s)cnt++;
            else if(a[0]+a[1]<=s)cnt+=2;
            else if(a[0]<=s)
            {
             if(a[1]+a[2]<=s)cnt+=2;
             else if(a[1]<=s)cnt+=3;
            }


        cout<<cnt<<endl;
    }
    return 0;
}
