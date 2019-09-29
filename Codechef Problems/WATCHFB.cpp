#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int flag=1,la=0,lb=0;
        for(int i=0;i<n;i++)
        {
            int a,b,pt;
        cin>>pt>>a>>b;
        if(a==b){cout<<"YES"<<endl;flag=1;}
        else if(pt==1){cout<<"YES"<<endl;flag=1;}
        else if(!flag){cout<<"NO"<<endl; }
        else if(min(a,b)<max(la,lb)){cout<<"YES"<<endl;flag=1;}
        else {cout<<"NO"<<endl;flag=0;}
        la=a;lb=b;
        }
    }
}
