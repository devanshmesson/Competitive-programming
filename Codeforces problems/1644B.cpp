// taskkill /IM "a.exe" /F
#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else 
#define freopen 
#endif
 
#define pb push_back
#define pf push_front
#define endl "\n"
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define float double


signed main()
{
  freopen
  ios
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    if(n==5)
    {
      cout<<1<<" "<<3<<" "<<2<<" "<<4<<" "<<5<<endl;
      cout<<1<<" "<<5<<" "<<4<<" "<<2<<" "<<3<<endl;
      cout<<1<<" "<<4<<" "<<3<<" "<<5<<" "<<2<<endl;
      cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<1<<endl;
      cout<<3<<" "<<2<<" "<<4<<" "<<5<<" "<<1<<endl;
      continue;

    }
    vector<int>ans(n+1);
    ans[1]=1;
    ans[2]=3;
    ans[3]=2;
    for(int i=4;i<=n;i++)ans[i]=i;

    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;



      
    
    int upd=3;
    int flag=0;
    while(1)
    {
      if(upd+1>n)break;
      swap(ans[upd],ans[upd+1]);
      if(flag==0)
      {
        swap(ans[2],ans[3]);
        if(n>5)swap(ans[5],ans[6]);

        // if(n==5)
        // {
        //   cout<<1<<" "<<4<<" "<<5<<" "<<2<<" "<<3<<endl;
        //   upd++;
        //   continue;
        // }
        flag=1;
      }
      if(n>6 && upd==4)swap(ans[6],ans[7]);
      upd++;
      
      for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
      cout<<endl;
    }

    for(int i=1;i<=n;i++)ans[i]=0;
    ans[1]=2;
    ans[n]=1;
    for(int i=2;i<n;i++)ans[i]=i+1;

      
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;

        

    swap(ans[1],ans[2]);
     for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;


     // if(yes==1)cout<<n<<endl;


  }
  
}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
