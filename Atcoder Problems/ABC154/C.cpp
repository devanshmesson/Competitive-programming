#include <bits/stdc++.h>

using namespace std;

int main()
{
  #define int long long int
    int n,flag=1;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1]){flag=0;break;}
    }
    if(flag==0)cout<<"NO"<<endl;
    else if(flag==1)cout<<"YES"<<endl;

    return 0;
}
