#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,diff=0,x,cnt=0;
    cin>>n>>d;
    vector<vector <int> > v;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)
        {
           cin>>x;
           vec.push_back(x);
        }
        v.push_back(vec);
        vec.clear();
    }
    int temp=0,t;
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {

           for(int k=0;k<d;k++)
           {
               temp=v[i][k]-v[j][k];
               diff+=temp*temp;
           }
           t=sqrt(diff);
           if(t*t==diff) cnt++;
           diff=0;

       }
    }
    cout<<cnt<<endl;
    return 0;
}
