#include<bits/stdc++.h>
using namespace std;
main()
{ 
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,greater<int>());

    if(n==1){cout<<"first"<<endl;continue;}
    else if (n==2)
    {
      if(a[0]>a[1]){cout<<"first"<<endl;continue;}
      else if(a[1]>a[0]){cout<<"second"<<endl;continue;}
       else if(a[1]==a[0]){cout<<"draw"<<endl;continue;}
    }

    int turn=0;

    int p1=0,p2=0;

    p1+=a[0];
    p2+=a[1]+a[2];
    int i=3;
    while(i<n)
    {
    if(turn){p2+=a[i];turn=0;}
    else {p1+=a[i];turn=1;}
    i++;
    }

    int p3=0,p4=0;

    p4=a[0];
    p3+=a[1]+a[2];
    i=3;
    turn=0;
    while(i<n)
    {
    if(turn){p3+=a[i];turn=0;}
    else {p4+=a[i];turn=1;}
    i++;
    }

    if(p1==p3)cout<<"draw"<<endl;
    else if(p1>p3)cout<<"first"<<endl;
    else cout<<"second"<<endl;
  } 
}
