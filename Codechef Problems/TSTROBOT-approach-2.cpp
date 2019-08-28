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
        long long int n,x,cnt=0,a[200100],g,d;
        cin>>n;
        cin>>x;
       a[n]=x;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
                x--;
                a[i]=x;
            }
           if(s[i]=='R')
                {
                x++;
                a[i]=x;
                }

        }
         cout<<*max_element(a,a+n+1) - *min_element(a,a+n+1) +1<<endl;



    }
    return 0;
}
