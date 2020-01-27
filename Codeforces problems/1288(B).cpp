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
        int a,cnt=0,flag=1;
        string b;
        cin>>a>>b;
        if(b.size()==1)
         {
             char v=b[0];
             int p=v-'0';
             if(p==9)cout<<a<<endl;
             else cout<<0<<endl;
         }
         else
         {
             for(int i=0;i<b.size();i++)if(b[i]!='9'){flag=0;break;}
             if(flag==1)cout<<a*b.size()<<endl;
             else cout<<a*(b.size()-1)<<endl;
         }
   }

    return 0;
}
