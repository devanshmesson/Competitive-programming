/*
Problem-https://www.codechef.com/LRNDSA02/problems/PSHOT
Time complexity-O(n)
Approach-Update Scores when s[i]=='1' of both players
        -Keep Count of remaining moves of both players
        -Even if a Players scores a point in all of the remaining rounds and if that score is still less than the other player's score then we 
        can assure that other player will win.

*/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0,b=0,done1=0,done2=0,ans,ok=0;
    for(int i=0;i<(2*n);i++)
    {
      if(i%2==0 && s[i]=='1')a++;
      else if(i%2 && s[i]=='1')b++;
      if(i%2)done2++;
      else done1++;
      
      if(n-done2+b<a){ok=1;ans=i+1;break;}
      else if(n-done1+a<b){ok=1;ans=i+1;break;}
      
    }
    if(ok)cout<<ans<<endl;
    else cout<<2*n<<endl;
  }
}


