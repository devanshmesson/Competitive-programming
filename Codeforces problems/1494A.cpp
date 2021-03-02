#include "bits/stdc++.h"
using namespace std;

#define endl "\n"

int check(string f)
{
  stack<char>s;
  for(int i=0;i<f.size();i++)
  {
  	if(s.size()==0)s.push(f[i]);
  	else if(s.top()=='(' && f[i]==')')s.pop();
  	else s.push(f[i]);
  }
  
 // cout<<s.top()<<endl;
  if(s.size()==0)return 0;
  else return 1;
}

main()
{
 int t;
 cin>>t;
 while(t--)
 {
 	string s,v;
 	cin>>s;
 	v=s;
 	int d=s.size();

 	if(s[0]==s[s.size()-1]){cout<<"NO"<<endl;continue;}

 	char map[4];
 	for(int i=1;i<=3;i++)map[i]='p';
 	map[int(s[0])-64]='(';
 	map[int(s[d-1])-64]=')';
  int save;
  
  //Case 1
 	for(int i=1;i<=3;i++)if(map[i]=='p'){save=i;map[i]='(';}
 	for(int i=0;i<d;i++)
    {
       v[i]=map[int(s[i])-64];
   	} 
 	if(check(v)==0){cout<<"YES"<<endl;continue;}
    
    //Case 2
    map[save]=')';
    for(int i=0;i<d;i++)
    {
       v[i]=map[int(s[i])-64];
 	  }
 	if(check(v)==0){cout<<"YES"<<endl;continue;}
 	cout<<"NO"<<endl;

 }

}
