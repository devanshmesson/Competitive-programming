#include<bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long int
    ios::sync_with_stdio(0);cin.tie();cout.tie();

    int q;
    cin>>q;
    while(q--)
    {


    string s,t;
    int cnt=1,j=0,c1=0,s1=0;
    cin>>s;


    for(int i=0;s[i]!='\0';i++)
    {
        char c=s[i];
        if(s[i+1]==c)cnt++;
        else
        {
           t[j]=s[i-1];
           c1++;
           char c=(char)cnt;
           if(cnt<10)c1+=1;
           else if(cnt>=10 && cnt<100)c1+=2;
           else if(cnt>=100 && cnt<1000)c1+=3;
           else if(cnt==1000)c1+=4;
           cnt=1;
        }

    }

    for(int i=0;s[i]!='\0';i++){s1++;}


    if(c1<s1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
}
CHEA
