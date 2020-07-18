/*
Problem-Given a string of brackets(),Given a position in form of q queries,From That Position find minimum position ahead of it till which a non-empty balanced bracket subsequence 
is found. (https://www.codechef.com/problems/CLBRKT)
Complexity-O(n+q)
Approach-Use a Stack Pair, First Element - '(' and second element as its index in the input string.
        -Push '(' in the stack and whenever there comes a ')',check if stack is non empty and store the second element of the top() of stack 
        (index of '(' which is in top of stack) and pop it afterwards.
        -Previous point means that we are storing the index of ')'[closing] which is balancing '('[opening].
        -How we are storing? We are storing the index of closing bracket as value and the balanced opening bracket as key in unordered map.
        -If in the input the index is reffering to a closing bracket,the its "minimum index ahead" will be same as of the "minimum index ahead" of its next character.
        - Previous Point will we implemented in a single O(n) Loop.
*/
#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define endl "\n"
main()
{
 io
 int t;
 cin>>t;
 while(t--)
 {
  string s;
  cin>>s;
  int n;
  n=s.size();
  stack<pair<char,int>>stk;
  unordered_map<int,int>mp;
  for(int i=0;i<n;i++)     //Use a Stack Pair, First Element - '(' and second element as its index in the input string.
                          //-Push '(' in the stack and whenever there comes a ')',check if stack is non empty and store the second element of the top() of stack 
                          //(index of '(' which is in top of stack) and pop it afterwards.
  {
    if(s[i]=='(')
    {
     stk.push({'(',i});
    }
    else if(s[i]==')')
    {
      if(stk.size()>0)
      {
        if(stk.top().first='(')
          {
            mp[stk.top().second]=i;
            stk.pop();
          }
      }
    }
  }

  for(int i=n-2;i>=0;i--)
  {
    if(s[i]==')')mp[i]=mp[i+1];   //If in the input the index is reffering to a closing bracket,the its 
                                  //"minimum index ahead" will be same as of the "minimum index ahead" of its next character/
  }
  int q,a;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    cin>>a;
    a--;
    mp[a]!=0?cout<<mp[a]+1<<endl:cout<<-1<<endl;
  }
 } 
}
