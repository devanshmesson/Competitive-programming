//Online qualifiers 2018 1st problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int right=1000000000,flag=1;
        string s;
        cin>>s;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='.')
            {
                if(i+(s[i]-'0')<right)right=i-(s[i]-'0');
                else {flag=0;break;}
                if(right<0)right=0;
                if(right>n)right=n;
            }
        }
        if(flag==0)cout<<"unsafe"<<endl;
        else cout<<"safe"<<endl;
    }

}

