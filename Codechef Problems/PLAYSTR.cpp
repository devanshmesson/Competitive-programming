#include <iostream>


using namespace std;

int main()
{
    string s,r;
    int n,t,cnt,cnt1;
   cin>>t;
    while(t--)
    {
       cnt1=0;
       cnt=0;
    cin>>n;
    cin>>s;
    cin>>r;

    for(int j=0;j<n;j++)
    {
        if(s[j]=='0')
        {
            cnt++;
        }
        if(r[j]=='0')
        {
            cnt1++;
        }
    }
    if(cnt==cnt1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }

    return 0;
}
