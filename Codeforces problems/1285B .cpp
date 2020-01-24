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
        int n,a,sum=0,s=0,ans=INT_MIN,flag=0,f=0,f1=1,k=1;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>a;v.push_back(a);
            sum+=a;
            if(a!=0)k=0;//corner case(if all the elements are 0 the ans is NO because 0<=0)
        }
        if(k==1){cout<<"NO"<<endl;continue;}

        //Checking if there is atleast one positive element present
        for(int i=0;i<n;i++)
        {
            if(v[i]<0)flag=1;
            else{flag=0;break;}
        }
        //checking if all the numbers are positive so answer is YES
        for(int i=0;i<n;i++)
        {
            if(v[i]<0){f=0;break;}
            else f=1;
        }

        if(f==1){cout<<"YES"<<endl;continue;}

        if(flag==0)
        {
        //Applying Kadane's Algorithm
        //this loop is satifying that subarray is not equal to whole array
        for(int i=0;i<n-1;i++)
        {
           if(s+v[i]>0)s+=v[i];
           else s=0;
           ans=max(ans,s);
        }
        s=0;
        for(int i=1;i<n;i++)
        {
            if(s+v[i]>=0) s+=v[i];
            else s=0;
            ans=max(ans,s);
        }

        if(sum>ans){cout<<"YES"<<endl;}
        else cout<<"NO"<<endl;
        }
        else
        {
            sort(v.begin(),v.end(),greater<int>());
            if(v[n-1]>=sum){cout<<"NO"<<endl;}
        }


    }
    return 0;
}
