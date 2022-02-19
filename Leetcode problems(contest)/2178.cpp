class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) 
    {
        // #define int long long int
    long long int s=finalSum;
         vector<long long int>v;
        if(s%2==1)return v;
  // int s=10;
  long long int sum=2,upd=0;
  long long int ans=-1;
  long long int prefix[100005];
  while(1)
  {
    upd+=sum;
    sum+=2;
    ans++;
    if(upd>=1e10)break;
    prefix[ans]=upd;
  }
  long long int x=lower_bound(prefix,prefix+ans,s)-prefix;
 
  if(prefix[x]==s)
  {
    for(int i=0;i<=x;i++)v.push_back((i+1)*2);
  }
  else
  {
    long long int diff=s-prefix[x-1];
    long long int replace=(x*2)+diff;
    v.push_back(replace);
     for(int i=0;i<=(x-2);i++)v.push_back((i+1)*2);
  }
   return v;

        
    }
};
