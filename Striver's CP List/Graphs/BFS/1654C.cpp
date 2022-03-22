//https://codeforces.com/contest/1654/problem/C
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    int sum=0;
    map<int,int>present;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];present[a[i]]++;}
    if(n==1){cout<<"YES"<<endl; continue;}
    queue<int>q;
    //Explore the root node, if n>1
    q.push(sum);
    int weight_found=0,cut=0;

    while(cut<n-1 && !q.empty())
    {
      int n=q.front();
      q.pop();
      //Because we have explored this child node, consider it as one cut.
      cut++;
      //Defining the values of the child nodes.
      int child1,child2;
      if(n%2==0)child2=child1=n/2;
      else
      {
        child1=n/2;
        child2=child1+1;
      }
      int flag=0, choose=-1;
      /*If Child Node 1 exists in the input array, count it in the answer
        and don't explore(cut) it. Same goes for child node 2*/
      if(present[child1]>0){weight_found++; present[child1]--; flag++; choose=1;}
      if(present[child2]>0){weight_found++; present[child2]--; flag++; choose=2;}

      //If both child nodes are present in the weight array, dont explore them.
      if(flag==2)continue;
      
      if(choose==1)q.push(child2); //If only child1 was present, explore child2.
      else if(choose==2)q.push(child1); //If only child2 was present, explore child1.
      else  //If both were not present in the weight array, explore both.
      {
        q.push(child1);
        q.push(child2);
      }
    }
    //If we found all the weights, Answer is YES, otherwise NO.
    if(weight_found==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
