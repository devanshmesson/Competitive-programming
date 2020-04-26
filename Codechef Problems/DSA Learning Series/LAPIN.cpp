#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int
    #define pb push_back
    #define mk make_pair
   int t;
   cin>>t;
   while(t--)
   {
       string s;
       int flag=1;
       cin>>s;
       int r,w,x;
       vector<int>v(130);
       vector<int>f(130);
       vector<int>visit(130);
       int n=s.size();
       for(int i=0;i<n/2;i++)
       {
         r=(int)s[i];
         visit[r]=1;
         v[r]++;
       }
       x=n/2;
       if(n%2!=0){x++;}

       for(int i=x;i<n;i++)
       {
          w=(int)s[i];
          if(visit[w]!=1){flag=0;break;}
          f[w]++;
       }
       if(flag==0){cout<<"NO"<<endl;continue;}

        for(int i=0;i<n/2;i++)
        {
            w=(int)s[i];
            if(v[w]!=f[w]){flag=0;break;}
        }
        if(flag==0){cout<<"NO"<<endl;continue;}

        if(flag==1)cout<<"YES"<<endl;



   }
    return 0;
}


