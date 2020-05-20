#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include <algorithm>
//#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define freopen //comment
#endif
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	io
	//freopen
	string s;
	cin>>s;
	map<char,int>mp;
	set<char>st;
	for(int i=0;i<s.size();i++)
	{
		st.insert(s[i]);
		mp[s[i]]++;
	}
	set<char>::iterator i;
	int odd=0,even=0;
	for(i=st.begin();i!=st.end();i++)
	{
		if(mp[*i]%2==0)even++;
		else odd++;
	}
    vector<char>v;
    vector<char>rev;
	if(odd>1)cout<<"NO SOLUTION"<<endl;
	else 
	{
		for(i=st.begin();i!=st.end();i++)
	    {
		  if(mp[*i]%2==0)
		  {
		  	for(int j=0;j<mp[*i]/2;j++)
		  	{
              v.push_back(*i);
              rev.push_back(*i);
		  	}

		  }
	    }
	    reverse(rev.begin(),rev.end());

	    for(i=st.begin();i!=st.end();i++)
	    {
		  if(mp[*i]%2!=0)
		  {
		  	for(int j=0;j<mp[*i];j++)
		  	{
              v.push_back(*i);
		  	}

		  }
	    }
	   
	   for(int i=0;i<v.size();i++)cout<<v[i];
	   for(int i=0;i<rev.size();i++)cout<<rev[i];

	}
}      

