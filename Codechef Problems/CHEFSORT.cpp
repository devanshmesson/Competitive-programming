#include<bits/stdc++.h>
using namespace std;
#define freopen freopen("input.txt","r",stdin); freopen("output2","w",stdout);
#define endl "\n"   //without this line, running time=0.57 seconds | With this line, running time=0.08 seconds
int n;

void type2(int *a)
{ 
  for(int i=1;i<=n-1;i++)
  {
    if(a[i]>a[i+1]){cout<<2<<" "<<i+1<<" "<<a[i]-a[i+1]<<endl;}
  }
}

void type3(int *a,int largest)
{
  for(int i=1;i<=n;i++){ a[i]^=largest; }
  cout<<3<<" "<<n<<" "<<largest<<endl;
}

main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    int a[n+1];
    int largest=0;
    for(int i=1;i<=n;i++){cin>>a[i];largest|=a[i];}

    //count problematic pairs (a[i] > a[i+1])
    //if count <=  floor(n/2), then just apply type 2 and you are done!
    //else if count > floor(n/2), then reverse the inequality signs of all adjacent elements by applying type 3.
    //Now you have the problematic pairs < floor(n/2), now apply type 2 and you are done!
   
    int prob_pairs=0,same=0;
    for(int i=1;i<=n-1;i++) 
      {
        if(a[i]>a[i+1])prob_pairs++;
        else if(a[i]==a[i+1])same++;
      }
    
    if(prob_pairs <= (n/2))
    {
      cout<<prob_pairs<<endl;
      type2(a);
      continue;
    }
    
    cout<<n-prob_pairs-same<<endl;
    
    type3(a,largest);
    type2(a);
  }
}
