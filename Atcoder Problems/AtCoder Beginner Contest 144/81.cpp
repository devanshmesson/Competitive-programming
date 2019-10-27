#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,flag=1;
	vector<int>v;
	cin>>n;
	for (int i=1;i<=9;i++) if (n%i==0){v.push_back(i);}
	int s=v.size();
	for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {


                if(v[i]*v[j]==n){flag=0;cout<<"Yes"<<endl;break;}

        }
        if(flag==0)break;
    }
    if(flag==1)cout<<"No"<<endl;
	return 0;
}
