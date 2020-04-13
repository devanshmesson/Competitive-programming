#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,a,flag=1;
        cin>>n>>x;
        int c[n]={0};
        vector<int>v,z;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        int i=1,cnt=0;
        while(1)
        {
            flag=1;
            for(int j=0;j<n;j++)
            {
                //c[v[j]]++;
                if(i==v[j])
                {
                    flag=0;i++;z.push_back(v[j]);break;
                }
            }
            if(flag==1){z.push_back(i);cnt++;i++;}
            if(cnt==x)break;

        }
                sort(v.begin(),v.end());

                int s=*max_element(z.begin(),z.end());
                //cout<<"-----"<<s+1<<endl;
                int q=s+1;
                int f=-1;

                for(int i=0;i<n;i++)
                {
                 if(v[i]==q){flag=0;q++;f=max(f,v[i]);continue;}

                }

            cout<<max(f,s)<<endl;
    }
    return 0;
}
