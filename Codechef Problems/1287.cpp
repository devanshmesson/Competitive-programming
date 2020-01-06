#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio();cin.tie();cout.tie();
    #define int long long int
    int n,k,cnt=0;
    string s;
    cin>>n>>k;
    vector<string>v;
    for(int i=0;i<n;i++){cin>>s;v.push_back(s);}
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            string expect="";
            for(int x=0;x<k;x++)
            {
                if(v[i][x]==v[j][x])expect+=v[i][x];
                else
                {
                    if((v[i][x]=='S' && v[j][x]=='T')||(v[i][x]=='T' && v[j][x]=='S'))expect+='E';
                    else if((v[i][x]=='S' && v[j][x]=='E')||(v[i][x]=='E' && v[j][x]=='S'))expect+='T';
                    else expect+='S';
                }
            }
            if(binary_search(v.begin()+j+1,v.end(),expect))cnt++;

        }
    }
    cout<<cnt<<endl;
    return 0;
}
