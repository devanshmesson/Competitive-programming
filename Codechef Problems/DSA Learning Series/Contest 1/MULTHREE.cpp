#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int k,a,b,tem;
       cin>>k>>a>>b;
       if(k==2)
       {
           if((a+b)%3==0)cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
           continue;
       }
       else if(k==3)
       {
           if(((a+b)+(a+b)%10)%3==0)cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
           continue;
       }

       int ar[4]={2,4,8,6};
       int no=(k-3)/4;
       int rem=(k-3)%4;
       int sum=0,s=a+b;
       for(int i=0;i<4;i++){tem=(ar[i]*(a+b));tem%=10;sum+=tem;}
       sum*=no;
        sum+=(a+b)+(a+b)%10;
       for(int i=0;i<rem;i++){tem=(ar[i]*(a+b));tem%=10;sum+=tem;}

       if(sum%3==0)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;




    }
}
