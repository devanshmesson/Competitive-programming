/* Split the given string into minimum number of substrings with unique characters such that the concatenation of all the substrings will result in the given string.
Microsoft Online test!
Examples:

"dddd" --> ["d", "d", "d", "d"] --> answer should be 4.
"abab" --> ["ab", "ab"] --> answer should be 2.
*/

#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
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

  string s;
  cin>>s;
  set<char>st;
  int ans=0;
  for(int i=0;i<s.size();i++)
  {
    if(st.count(s[i]))
    {
      ans++;
      st.clear();
    }
    st.insert(s[i]);
  }
  cout<<ans+1<<endl;


}


    /*1.Never overkill a problem.
      2.think of test cases to clarify the approach/doubts.
      3.Don't give up!
      4.Always pass array/string by reference in recursive function.Otherwise, it will be TLE!
      5.don’t use multiplication operator unless necessary, Otherwise, it will be TLE!
      6.Check datatype of variables, sometimes wrong datatype lead to WA.
    */ 
    
    
