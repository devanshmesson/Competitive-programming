#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pb push_back
#define int long long int


main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,s;
    cin>>n>>s;
    int median;

    if(n%2==0)median=n/2;
    else median=(n/2)+1;

    int left_values=n-median+1;
    cout<<s/left_values<<endl;
  }
}
