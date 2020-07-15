/*Approach-Solve Greedily
          -Find Minimum element of the array, erase that element from the array and insert that element to the leftmost place possible.
          -leftmost place possible means when we shift the minimum element from its original place to the leftmost place so we swap adjacent elements(i and i+1).
          -According to Problem, We can only swap two particular adjacent elements once.So when we again find the minimum element then we will find from the place 
            on which the previous minimum element was found because we cant do operations(swap) before the position of the previous minimum element(read 2nd point).
           - And this process continues.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,b,upd=0,mindex=0;
  cin>>n;
  vector<int>a;
  for(int i=0;i<n;i++){cin>>b;a.pb(b);}
  while(1)
  {
    mindex=min_element(a.begin()+upd,a.end())-a.begin();
    if(mindex>=n)break;
    int put=a[mindex];
    a.erase(a.begin()+mindex);
    a.insert(a.begin()+upd,put);
    if(mindex==upd)upd=mindex+1;
    else upd=mindex;
  }
  for(int i=0;i<n;i++)cout<<a[i]<<" ";
  cout<<endl;
 }
  return 0;
}
