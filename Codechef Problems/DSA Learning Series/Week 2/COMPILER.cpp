/*
Problem-Length of the Longest Valid Prefix in a string containing '<' and '>'
Another Way of putting it  -  Length of Longest Continuous Balanced brackets form 0th index.
       -Examples of Valid prefix
         -<><><><> length-8
         -<><<>>   length-6
         -<>>      length-2
         - ><<>    length-0

Time Complexity-O(n)
Data Structure used - Stack
Approach- when there comes '<' push in stack.
         -when there comes '>' increase ans by 1 and stack.pop()
         -if invalid string occurs in between then we break.
         -if stack is empty and there comes '>' , so this is invalid because a balanced bracket sequence cant start from it.
         -Answer must be updated when when stack gets empty as we are now assured that it was a valid sequence
*/
#include<bits/stdc++.h>
using namespace std;
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string a;
    cin>>a;
    stack<char>s;
    int ans=0,cnt=0,flag=0;
    for(int i=0;i<a.size();i++)
    {
      if(a[i]=='<') s.push('<');
      else if(a[i]=='>')
      {
        if(!s.empty())
        {
          if(s.top()=='<')
            {
              cnt++;
              s.pop();
              if(s.empty())
                {
                  ans=max(ans,2*cnt);   //Answer must be updated when when stack gets empty as we are now assured that it was a valid sequence
                }    
            }
        }
        else break;     // if stack is empty and there comes '>' , so this is invalid because a balanced bracket sequence cant start from it.
      } 
    }
    cout<<ans<<endl;
  }
}
