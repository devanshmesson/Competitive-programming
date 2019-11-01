#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,p=0,c=0;
        cin>>n;
        if(n==1){cout<<"0"<<endl; continue;}
        if(n>=2 && n<4) {cout<<"1"<<endl; continue;}

               while(n>>=1)
               {
                   p<<=1;
                   c++;
               }

                if(c%4==0){cout<<"0"<<endl;}
                else if(c%4==2){ cout<<"2"<<endl;}
                else if(c%4==3){cout<<"3"<<endl; }
                else if(c%4==1){cout<<"9"<<endl;}


    }
    return 0;
}
