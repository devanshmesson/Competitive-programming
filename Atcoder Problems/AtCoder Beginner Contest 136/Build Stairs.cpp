#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,flag=1,s;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }

   for(int i=0;i<n-1;i++)
   {
       if(v[i]>=v[i+1])
       {
           if(v[i]-v[i+1]>1)
           {
               cout<<"No"<<endl;
               return 0;
           }
           else if(v[i]-v[i+1]==1)
           {
              v[i]--;
           }
           else if(v[i]==v[i+1])
           {
               if(i == 0) v[i]--;
               else
                {
                  if(v[i-1]!=v[i])
                  {
                    v[i]--;
                  }
                }
           }
        }
   }
   for(int i=0;i<n-1;i++)
   {
       if(v[i]>v[i+1]){cout<<"No"<<endl;return 0;}
   }
   cout<<"Yes"<<endl;
    return 0;
}
