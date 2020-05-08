#include<bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
     int n,k,c=0;
     vector<int>d;
     cin>>n>>k;
     int a[n+1],b[n+1];
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
         if(a[i]%2!=0){c++;b[i]=0;}
         if(a[i]%2==0){b[i]=1;}
     }

     if(c%2!=k%2|| c<k){cout<<"NO"<<endl;continue;}

     if(c%2==k%2 && c>=k)
     {
         cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
         {
             if(k==1)break;
             if(b[i]==0)
             {
                 cout<<i+1<<" ";
                 k--;
             }
         }
        cout<<n<<endl;
    }


    }
}
