class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) 
    { 
      const long long int mod=1e9+7;
      int n=nums1.size();
      int m=nums2.size();
      vector<pair<int,int>>v;
      map<int,int>mp;
        
      vector<long long int>pref1(n+1,0),pref2(m+1,0);
        
      long long int sum=0;
        
      for(int i=0;i<n;i++)
      {
        mp[nums1[i]]=i;
        sum=sum+nums1[i];
        pref1[i]=sum;
      }  
     
      sum=0;
      for(int i=0;i<m;i++)
      {
        if(mp[nums2[i]]==0 && nums1[0]==nums2[i])v.push_back({0,i});
        else if(mp[nums2[i]]>0)v.push_back({mp[nums2[i]],i});
        sum=sum+nums2[i];
        pref2[i]=sum;
      }   

      int sz=v.size();
      if(sz==0)
      {
          return max(pref1[n-1],pref2[m-1]);
      }
      long long int ans=0;
      long long int x,y;
      int idx1=v[0].first-1,idx2=v[0].second-1;
      if(idx1>=0 && idx2<0)ans=pref1[idx1];
      else if(idx1<0 && idx2>=0)ans=pref2[idx2];
      else if(idx1<0 && idx2<0);
      else if(pref1[idx1]>pref2[idx2])ans=pref1[idx1];
      else ans=pref2[idx2];
        
      for(int i=1;i<sz;i++)
      {
          int nx1=v[i].first-1,nx2=v[i].second-1;
          if(idx1<0)x=pref1[nx1];
          else x=pref1[nx1]-pref1[idx1];
          
          if(idx2<0)y=pref2[nx2];
          else y=pref2[nx2]-pref2[idx2];
          
          ans=(ans+max(x,y))%mod;
          idx1=nx1;
          idx2=nx2;
      }
      if(idx1<0)x=pref1[n-1];
      else x=pref1[n-1]-pref1[idx1];
      if(idx2<0)y=pref2[m-1];
      else y=pref2[m-1]-pref2[idx2];
      ans=(ans+max(x,y))%mod;
      return ans;
    }
};
