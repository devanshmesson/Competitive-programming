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
        int a,b,c,flag=0,cnt=0;
        cin>>a>>b>>c;
        vector<int>v;
        v.push_back(a);
         v.push_back(b);
          v.push_back(c);

            sort(v.begin(),v.end(),greater<int>());

          //if(a==0 || b==0 || c==0)flag=1;



          for(int i=0;i<3;i++)
          {
              v[i]--;
              if(v[i]>=0){cnt++;}
          }

           flag=0;
          for(int i=0;i<=1;i++)
          {
              v[i]--;
              if(v[i]<0){flag=1;break;}
          }
          if(flag==0)cnt+=1;

 flag=0;
          for(int i=1;i<=2;i++)
          {
              v[i]--;
              if(v[i]<0){flag=1;break;}
          }
         if(flag==0)cnt+=1;

 flag=0;
          for(int i=0;i<3;i+=2)
          {
              v[i]--;
            if(v[i]<0){flag=1;break;}
          }
          if(flag==0)cnt+=1;
 flag=0;
          for(int i=0;i<3;i++)
          {
              v[i]--;
              if(v[i]<0){flag=1;break;}
          }
          if(flag==0)cnt+=1;
          cout<<cnt<<endl;





    }
    return 0;
}
