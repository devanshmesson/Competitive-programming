#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define int long long int

       int n,sum=0,sum1=0,ans=0,flag=1,k=0,l=0,in;
       cin>>n;
       int a[n],b[n];
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
         //  if(a[i]==b[i])k++;
       }
       for(int i=0;i<n;i++)
       {
           cin>>b[i];
       }
       for(int i=0;i<n;i++)
       {
           if(a[i]==1 && b[i]==0){flag=0;break;}
       }
       if(flag==1){cout<<-1<<endl;return 0;}

       for(int i=1;i>=0;i++)
       {
           flag=1;
           sum=0;sum1=0;
           for(int j=0;j<n;j++)
           {
               if(a[j]==1 && b[j]==0)sum+=i;
               if(a[j]==1 && b[j]==1)sum+=1;
           }
           for(int j=0;j<n;j++)
           {
               if(b[j]==1)sum1+=1;
           }
           //cout<<sum<<" "<<sum1<<endl;
           if(sum>sum1){flag=0;in=i;break;}
       }
       cout<<in<<endl;




    return 0;
}
