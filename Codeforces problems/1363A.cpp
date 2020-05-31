/*Problem-If its Possible to have "x" elements in an array whose sum is odd.
  Time Complexity-O(n)
  Corner cases-if "x"="n" then odd numbers should be odd in number.
              -if all the elements in the array are odd then x should be odd.
  Points-frequency of odd numbers >0
 */
#include<bits/stdc++.h>
using namespace std;
ain() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x;
    cin>>n>>x;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    int od=0,even=0;
    for(int i=0;i<n;i++)
    {
      if(a[i]%2!=0)od++;
      else even++;
    }
    if(od==n && x%2==0){cout<<"No"<<endl;continue;}
    if(x==n && od%2==0){cout<<"No"<<endl;continue;}
    if(od>0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
   }
}
