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
        int n,k,sum=0,flag=1,tm=0;
        cin>>n>>k;
        int a[n+10000];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
        {
            flag=1;
            if(a[i]<k && a[i]%k!=0){sum+=a[i];}
            else if(a[i]>k && a[i]%k!=0){sum+=a[i]%k;}
            tm=sum;
                for(int j=i+1;j<n;j++)
                {
                    if((sum<(k-(a[j]%k))) && a[j]%k!=0){flag=0;break;}
                    else if((sum>=(k-(a[j]%k))) && a[j]%k!=0){sum-=(k-(a[j]%k));if(sum<0)break;}
                }
                if(flag==0)sum=tm;
                else if(flag==1){break;}     
        }
      cout<<sum<<endl;


    }

    return 0;
}
