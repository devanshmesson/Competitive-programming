#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v;
int gcd(int a,int b)
{
    if(a<b)return gcd(b, a);
    int r;
    while((r=a%b)) { a = b;b = r;}
    return b;
}

int comm(int a,int b)
{
    int n=gcd(a,b);
    int result=0,flag=1,cnt=0;
    if(n%2==0){cnt++;while(n%2==0)cnt++;n=n/2;}
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        if(n%i==0){cnt++;while(n%i==0)n=n/i;}
    }
    if(n>2)cnt++;
    return cnt;

}
main()
{
	int a,b;
	vector<int> v;
	cin>>a>>b;
	cout<<comm(a,b)+1;
}
