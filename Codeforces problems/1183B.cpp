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
           int n,k,in;
           cin>>n>>k;
            int a[n+100];
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       sort(a,a+n);

      if(abs(a[n-1]-(a[0]+k))>k)cout<<-1<<endl;
      else cout<<a[0]+k<<endl;

       }


    return 0;
}
