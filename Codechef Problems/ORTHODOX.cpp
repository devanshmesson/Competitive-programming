/*
Problem-Check if OR of elements between all possible pairs of indexes in the input array is pairwise distinct or not.
Time Complexity-O(n^2) (n<=60)
Constraints-n<=10^5 and T=300 and a[i]<=10^18
New Information-Every Number should have a set bit which is not set in numbers which comes before it.
Approach -If Number of elements in the array is greater then 60 then Output is always "NO",
         -Previous Point Means that if every Number gives some new information and n>60,Log2(10^18)~60
          then after ORing 60 elements all 60 bits will be set and 61st number will be <=10^18 
           and ORing with the 61st number will Repeat the OR result.

         -Else if n<=60 then we have to bruteforce OR on all Possible pairs that will obviously come under time limit of 1 second.
         -We cant figure out in O(n) if n<=60
          300*60*60<10^8
*/
#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
main()
{
  io
  int t;
  cin>>t;
  while(t--)
  {
    int n,flag=1;
    cin>>n;
    int a[n+1];
    map<int,int>mp;
    for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]++;}
    if(n>60){cout<<"NO"<<endl;continue;}

    for(int i=0;i<n;i++)
    {
      int x=a[i];
      flag=1;
      for(int j=i+1;j<n;j++)
      {
        x|=a[j];
        if(mp[x]){flag=0;break;}
        mp[x]++;
      }
      if(flag==0)break;
    }
    if(flag==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }

  
}
