#include <iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r;
    cin>>r;
    while(r--)
    {
    vector<int> v;
    int n;
    cin>>n;
    int t=n;

    while (t!=0)
    {
       int y=t%10;
        t=t/10;
        v.push_back(y);
    }
    int k=v.size();
    int h=v[0]+v[1];
    cout<<v.front()+v.back();
    cout<<endl;
    }




    return 0;

}
