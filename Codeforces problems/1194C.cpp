#include <bits/stdc++.h>
using namespace std;
int main()
{
string s,t,p;

   int q;
   cin>>q;
   for(int x=0;x<q;x++)
   {
       cin>>s;
       cin>>t;
       cin>>p;

       if(p.size()+s.size()<t.size()){cout<<"NO"<<endl;continue;}

       int in[130]={0},k;
       for(int i=0;i<p.size();i++)
       {
           k=(int)p[i];
           in[k]++;
       }
      int i=0,j=0,flag=0;
      while(i<s.size())
      {
          k=(int)t[j];
          if(j>=t.size()){flag=1;break;}

          if(s[i]==t[j]){i++; j++;}
          else if(s[i]!=t[j])
          {
            in[k]--;
            j++;
          }
          if(in[k]<0){flag=1;break;}
      }
      if(flag==0)
      {
          while(j<t.size())
          {
              k=(int)t[j];
              in[k]--;
              if(in[k]<0){flag=1;break;}
              j++;
          }
      }
      if(flag==1)
      {
          cout<<"NO"<<endl;
          continue;
      }
      sort(in,in+130);
      if(in[0]<0)cout<<"NO"<<endl;
      else cout<<"YES"<<endl;





   }
    return 0;
}
