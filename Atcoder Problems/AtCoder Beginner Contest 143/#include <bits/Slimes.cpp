#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,i=0,cnt=0;
  string s;
  cin>>n>>s;

  while(s[i]!='\0')
  {
      if(s[i]!=s[i+1])cnt++;
      i++;
  }
  cout<<cnt<<endl;

    return 0;
}
