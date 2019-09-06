#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x,sum=0,sum1=0;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin>>x;
	    v.push_back(x);
	}
	int i=0,j=n;
	
	while(1)
	{
	  sum=sum+v[i];
	  j--;
	  if(i==j) break;
	  sum1=sum1+v[j];
	  i++;
	  if(i==j)break;
	}
	cout<<sum1-sum<<endl;
	return 0;
}
