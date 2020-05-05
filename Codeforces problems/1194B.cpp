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
       int n,m;
       cin>>n>>m;
       char a[n+1][m+1]={0};
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               cin>>a[i][j];
           }
       }
       int cn[n+1]={0};
       int cn1[m+1]={0};
       
       for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
         {
            cn[i] += (a[i][j] == '.');
			cn1[j] += (a[i][j] == '.');
         }
		
    
        int mi=INT_MAX,ans;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
             if(a[i][j]=='.')
             {
               ans=cn[i]+cn1[j]-1;
             }
             else ans=cn[i]+cn1[j];
             mi=min(mi,ans);
            }
        

        cout<<mi<<endl;



   }
    return 0;
}
