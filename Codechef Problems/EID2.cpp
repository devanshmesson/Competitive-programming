#include <bits/stdc++.h>
using namespace std;

bool sortbysec(pair<int,int> &a,pair<int,int> &b)
{
    return a.first>b.first;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,flag=1;
        vector< pair <int,int> > v;
        vector<int> c;
        vector<int> a;
        for(int i=0;i<3;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<3;i++)
        {
            cin>>x;
            c.push_back(x);
        }
        for(int i=0;i<3;i++)
        {
            v.push_back(make_pair(a[i],c[i]));
        }

        sort(v.begin(),v.end(),sortbysec);


        for(int i=0;i<2;i++)
        {
            if(v[i].second<v[i+1].second)
            {
                cout<<"NOT FAIR"<<endl;
                flag=0;
                break;
            }
            else if(v[i].first==v[i+1].first)
            {
                if(v[i].second==v[i+1].second)
                {
                    flag=1;
                }
                else 
                {
                    flag=0;
                    cout<<"NOT FAIR"<<endl;
                    break;
                }
            }
            else if(v[i].second==v[i+1].second)
            {
                if(v[i].first!=v[i+1].first)
                {
                    flag=0;
                     cout<<"NOT FAIR"<<endl;
                    break;
                }
            }
        }
        if(flag==1)cout<<"FAIR"<<endl;

    }
    return 0;
}
