#include <iostream>
using namespace std;

int main()
{
   #define int long long int
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
       int n,k,temp=0,cnt=0;
       cin>>n;
       int a[n+20][n+20]={0};
       if(n%2==0){cout<<"NO"<<endl;continue;}
       else
       {
           cout<<"YES"<<endl;
      for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               a[i][j]=0;
           }
       }
          for(int i=3;i<=n;i+=2){cnt++;}
          temp=cnt;
          for(int j=0;j<n;j++)
          {
              k=(j+1)%n;
              temp=cnt;
              while(temp!=0)
              {
                  a[j][k]=1;
                  k++;
                  k=k%n;
                  temp--;
              }
          }

       }
       for(int i=0;i<n;i++)
          {
              for(int j=0;j<n;j++)
              {
                  cout<<a[i][j];
              }
              cout<<endl;
          }
   }
}
