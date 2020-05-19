#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int

int32_t main()
{
	  io
    int t;
    cin>>t;
    while(t--)
    {
    	int x,y,a,b,flag=1,s;
    	cin>>x>>y;
    	a=max(x,y);

    	  if(max(x,y)==x)flag=0;
       	else flag=1;

    	if(max(x,y)%2==0)
    	{
    		if(flag)
    		{
    		    s=a*a;
    			s-=(a-1);
    			s-=(a-x);
    		}
    		if(!flag)
    		{ 
    			 s=a*a;
                 s-=(y-1);
       	    }
    		cout<<s<<endl;
       }
       else if(max(x,y)%2!=0)
       {

          if(x==y)
          {
          	  s=a*a;
              s-=(x-1);
              cout<<s<<endl;
              continue;
          }

       	  if(!flag)
    		{
    			s=a*a;
    			s-=(a-1);
    			s-=(a-y);
    		}
    	   if(flag)
    		{
    		  s=a*a;
              s-=(x-1);
            }
    	    
    	    cout<<s<<endl;
    	}
    }   
}                                            
