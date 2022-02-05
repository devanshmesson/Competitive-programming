class Solution
{
    public:
    vector<int> help(int n, int ok)
    {
      vector<int>p;
      int temp=n;
      if(n==0)p.push_back(0);
      while(n>0)
      {
        int k=n%10;
        n/=10;
        p.push_back(k);
      } 
      if(temp<10 && ok==1)p.push_back(0);
      reverse(p.begin(),p.end());
      return p;
    }
    int dotask(vector<int>clock, int upd, int p, int m)
    {
        int ans=0;
        for(int i=0;i<clock.size();i++)
        {
          if(clock[i]==upd)ans+=p;
          else 
          {
            upd=clock[i];
            ans+=m+p;
          }
        }
        return ans;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) 
    {
      int s=startAt,m=moveCost,p=pushCost,t=targetSeconds;
      int minu=t/60;
      int sec=t-(minu*60);
      int ans=0;
      if(minu==100)
      {
          minu--;
          sec+=60;
      }
      if(t<=99)
      {
        vector<int>clock;
        if(t>=60)
        {    
            int temps=s;
            int tempt=t-60;
            if(temps==1)ans+=p;
            else {ans+=m+p; temps=1;}
            clock=help(tempt,1);
            ans+=dotask(clock,temps,p,m);
        }  
        clock=help(t,0);
        int ans1=dotask(clock,s,p,m);
        cout<<ans1<<" "<<ans<<endl;
        if(ans==0)return ans1;
        return min(ans,ans1);
      }
      else
      {   
          int diff=99-sec;
          diff/=60;
          int mini=INT_MAX;
          do
          {
             ans=0;
             vector<int>m1=help(minu,0);
             vector<int>s1=help(sec,1);
             ans+=dotask(m1,s,p,m);
             int upd=minu%10;
             ans+=dotask(s1,upd,p,m);
             mini=min(mini,ans);
             if(minu>1)
             {
              minu--;
              sec+=60;
             }
          }while(diff--);
          return mini;
      }
    }
};
