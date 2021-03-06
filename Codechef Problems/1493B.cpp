#include<bits/stdc++.h>
using namespace std;


int verify(int n)
{
  int num=n;
  while(num>0)
  {
    int temp=num%10;
    num/=10;
    if(temp!=1 && temp!=2 && temp!=5 && temp!=8 && temp!=0){return 0;}
  }
  return 1;
}
 
vector<int> string_to_int(string s)
{
  vector<int>v;
  int a=(int)s[0]-48;a*=10;a+=(int)s[1]-48;
  int b=(int)s[3]-48;b*=10;b+=(int)s[4]-48;
  v.push_back(a);
  v.push_back(b);
  return v;
}

int singledigit(int n)
{
  int num=n;
  int cnt=0;
  if(num==0)return 1;
  while(num>0)
  {
    int temp=num%10;
    num/=10;
    cnt++;
  }
  if(cnt==1)return 1;
  else if(cnt==2)return 0;
}

int reverse_num(int n)
{
  int temp=n;
  int cnt=0,ans=0;
  while(temp>0)
  {
    int rem=temp%10;
    temp/=10;
    cnt++;
    if(rem==2)rem=5;
    else if(rem==5)rem=2;
    if(cnt==1)
      {
        ans=rem*10;
      }
    else ans+=rem;
  }
  return ans;
}

main()
{
 int t;
 cin>>t;
 while(t--)
 {
   int h,m;
   cin>>h>>m;
   string s;
   cin>>s;
   vector<int>time=string_to_int(s);
   int hours=time[0],minutes=time[1];
   //cout<<hours<<" "<<minutes<<endl; 
   reverse(s.begin(),s.end());

   for(int i=0;i<s.size();i++)
   {
     if(s[i]=='2')s[i]='5';
     else if(s[i]=='5')s[i]='2';
   }
   vector<int>mirrortime=string_to_int(s);
   int mhours=mirrortime[0],mminutes=mirrortime[1];
   
   //cout<<mhours<<" "<<mminutes<<endl;
   if(mhours<=h-1 &&  mminutes<=m-1 && verify(mhours)==1 && verify(mminutes)==1)
   {
     reverse(s.begin(),s.end());
     for(int i=0;i<s.size();i++)
   {
     if(s[i]=='2')s[i]='5';
     else if(s[i]=='5')s[i]='2';
   }
     cout<<s<<endl;
     continue;
   }

   int hrs=hours,mints=minutes,revh,revm;

   while(1)
   {
     mints++;
     mints%=m;
     if(mints==0)
      {
        hrs++;
        hrs%=h;
      }
      if(verify(hrs)==1 && verify(mints)==1)
      {
        revh=reverse_num(hrs);
        revm=reverse_num(mints);

         if(revm<=h-1 && revh<=m-1)
         {
            
            break;
         }
      }
   }

   if(singledigit(hrs)==1)cout<<0<<hrs<<":";
   else if(singledigit(hrs)==0)cout<<hrs<<":";

   if(singledigit(mints)==1)cout<<0<<mints<<endl;
   else if(singledigit(mints)==0)cout<<mints<<endl;   
 }
}
