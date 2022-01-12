#include<bits/stdc++.h>
using namespace std;
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,x;
    cin>>m>>x;
    m--;
    int winner[x+1];
    winner[1]=0;
    int start=0;
    cout<<1<<" ";
    for(int i=2;i<=x;i++)
    {
       start=0;
       int cut=m%i;
       if(start==cut)start++;
       if(cut>start && cut<=(start+winner[i-1]))winner[i]=start+winner[i-1]+1;
       else winner[i]=start+winner[i-1];
       cout<<winner[i]+1<<" ";
    }
    cout<<"\n";
  }   
}
/*1.Never overkill a problem.
 2.think of test cases to clarify the approach/doubts.
*/ 
