/*
Problem - Given two strings a and b.Task is to convert a to b.
To convert a to b , an operation is defined -
-Choose a substring in 'a' and flip all elements(1->0 OR vice-verca) which are at odd indexes in the substring.

If only odd indexes are to be flipped , it means in one operation either we can flip elements at even indexes of string 'a'
or we can flip elements at odd indexes of string 'a'.

Maximum number of operations to convert from a to b = number of unmatched characters (take each unmatched individual element as a substring and flip it).

To minimize it, we should group some elements in which we get number of operations as 1.

For example,
a=1010
b=0000

we have to flip elements at odd indexes in string a which can be done in only one operation.
So flip elements which are together with no gap like 1,3,5 or 2,4,6.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define pb push_back
main()
{
   int t;
   cin>>t;
   while(t--)
   {
   string a,b;
   cin>>a;
   cin>>b;
   vector<int>odd,even;
   int sz=a.size();
   for(int i=0;i<a.size();i++)
   {
     if(a[i]!=b[i] && (i+1)%2==0)even.pb(i+1);
     else if(a[i]!=b[i] && (i+1)%2==1)odd.pb(i+1);
   }
   
   int x = even.size() + odd.size();
   int ans=0;
   if(even.size()>0)ans++;


   for(int i=1;i<even.size();i++)
   {
     int z=abs(even[i]-even[i-1]);
     z/=2;
     z--;
     if(z>=1)ans++;
   }

     if(odd.size()>0)ans++;

     for(int i=1;i<odd.size();i++)
     {
     int z=abs(odd[i]-odd[i-1]);
     z/=2;
     z--;
     if(z>=1)ans++;
     }
     cout<<min(ans,x)<<endl;
   }  
}
