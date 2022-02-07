//Link - https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/submissions/
class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
      int n=nums.size();
      int start=(n/3);
      vector<int>exchange(start+1);
      long long int sum1=0,sum2=0;
      priority_queue<int>p;
      priority_queue<int, vector<int>, greater<int> > q;
      for(int i=0;i<(start);i++){p.push(nums[i]);sum1+=nums[i];}
      for(int i=start;i<(2*start);i++)exchange[i-start+1]=nums[i];
      for(int i=n-1;i>=(n-start);i--){q.push(nums[i]);sum2+=nums[i];}

      long long int a1[start+1],b1[start+1];
      a1[0]=sum1;
      b1[start]=sum2;

      long long int pupd=sum1,qupd=sum2;
      for(int i=1;i<=start;i++)
      {
        int ptop=p.top();
        if(exchange[i]<ptop)
        {
          p.pop();
          p.push(exchange[i]);
          pupd-=ptop;
          pupd+=exchange[i];
          a1[i]=pupd;
        }
        else a1[i]=a1[i-1];
        int qtop=q.top();
        int in=start-i+1;
        if(exchange[in]>qtop)
        {
          q.pop();
          q.push(exchange[in]);
          qupd-=qtop;
          qupd+=exchange[in];
          b1[start-i]=qupd;
        }
        else b1[start-i]=b1[start-i+1];
      }

      long long int mini=1e18;

      for(int i=0;i<=start;i++)
      {
        mini=min(mini,a1[i]-b1[i]);
      }
      return mini;  
    }
};
