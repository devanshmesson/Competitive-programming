#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,cnt=0;
    cin>>t;
    while(t--)
    {
        cnt=0;
        string s;
        cin>>s;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
        }
        if(cnt%2==0)
        {
            cout<<"LOSE"<<endl;
        }
        else
        {
            cout<<"WIN"<<endl;
        }
    }

	return 0;
}
