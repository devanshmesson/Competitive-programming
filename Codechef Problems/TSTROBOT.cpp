#include <iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main()
{
   int t;
    cin>>t;
    while(t--)
    {
        long long int n,x,mx=0,mn=0,c=0;
        cin>>n;
        cin>>x;
        string s;
        cin>>s;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='L') c--;
            else c++;
                mx=max(c,mx);
                
                mn=min(c,mn);
                
        }
cout<<mx-mn+1<<endl;



    }
    return 0;
}
