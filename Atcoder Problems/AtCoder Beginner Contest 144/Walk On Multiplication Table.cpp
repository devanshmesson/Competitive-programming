#include <bits/stdc++.h>
using namespace std;

int main()
{
    #define int long long int
	int n,flag=1,t1,t2,minm=INT_MAX,t=0,p=0;
	vector<int>v;
	cin>>n;

    
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) v.push_back(i);  
            else {v.push_back(i);v.push_back(n/i);}
        } 
    } 
 
	int s=v.size();
	for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
         if(v[i]*v[j]==n){t1=v[i];t2=v[j];}
         if(t1-t2<minm){minm=fabs(t1-t2);t=t1;p=t2;}


        }
    }
      cout<<(t-1)+(p-1)<<endl;
	return 0;
}
