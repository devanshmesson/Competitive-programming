/*
 Perform bruteforce by considering all permutations of U R D L
  then colour the boundaries black.
*/
#include "bits/stdc++.h"
using namespace std;

#define endl "\n"

int ur,ul,dr,dl;
int n,u,r,d,l;
int n1,u1,r2,l2,d1;


int ans=0;

void permute(char a[],int l1,int r1)
{
  if(l1==r1)
  {
     int bound=n-2;

     for(int i=0;i<4;i++)
     { 
        if(a[i]=='u')
        {
        	
        	int req=u-bound;
        
        	if(req==1 && l>0 && ul>0)
        	{
               u=0;
               l--;
               ul--;
        	}
        	else if(req==1 && r>0 && ur>0)
        	{
               u=0;
               r--;
               ur--;
        	}
        	else if(req==2 && l>0 && ul>0 && r>0 && ur>0)
        	{
               u=0;
               l--;
               r--;
               ul--;
               ur--;
        	}
        	else if(req<=0)u=0;
        	else if(req!=0){break;}
        }

        else if(a[i]=='r')
        {
            int req=r-bound;
        
        	if(req==1 && u>0 && ur>0)
        	{
               r=0;
               u--;
               ur--;
        	}
        	else if(req==1 && d>0 && dr>0)
        	{
               r=0;
               d--;
               dr--;
        	}
        	else if(req==2 && u>0 && ur>0 && d>0 && dr>0)
        	{
               r=0;
               u--;
               d--;
               ur--;
               dr--;
        	}
        	else if(req<=0)r=0;
        	else if(req!=0){break;}


        } 

        else if(a[i]=='l')
        {
        	
        	int req=l-bound;
       

        	if(req==1 && u>0 && ul>0)
        	{
               l=0;
               u--;
               ul--;
        	}
        	else if(req==1 && d>0 && dl>0)
        	{
               l=0;
               d--;
               dl--;
        	}
        	else if(req==2 && u>0 && ul>0 && d>0 && dl>0)
        	{
               l=0;
               u--;
               d--;
               ul--;
               dl--;
        	}
        	else if(req<=0)l=0;
        	else if(req!=0){break;}
        }
        else if(a[i]=='d')
        {
        	
        	int req=d-bound;
    
        	if(req==1 && l>0 && dl>0)
        	{
               d=0;
               l--;
               dl--;
        	}
        	else if(req==1 && r>0 && dr>0)
        	{
               d=0;
               r--;
               dr--;
        	}
        	else if(req==2 && l>0 && dl>0 && r>0 && dr>0)
        	{
               d=0;
               l--;
               r--;
               dl--;
               dr--;
        	}
        	else if(req<=0)d=0;
        	else if(req!=0){break;}
        }


     }

    if(u==0 && l==0 && r==0 && ul>=0 && ur>=0 && dl>=0 && dr>=0 && d==0){ans=1;}
    d=d1;
 	u=u1;
 	r=r2;
 	l=l2;

 	ur=1,ul=1,dr=1,dl=1;
  }
  for(int i=l1;i<r1;i++)
  {
  	swap(a[i],a[l1]);
  	permute(a,l1+1,r1);
  	swap(a[i],a[l1]);
  }
}

main()
{
 int t;
 cin>>t;
 while(t--)
 {
 	
 	ur=1,ul=1,dr=1,dl=1;
 	cin>>n>>u>>r>>d>>l;
    ans=0;
 	d1=d;
 	u1=u;
 	r2=r;
 	l2=l;

 	char a[4]={'u','r','d','l'};
 	permute(a,0,4);

 	if(ans==1)cout<<"YES"<<endl;
 	else cout<<"NO"<<endl;
 }

}
