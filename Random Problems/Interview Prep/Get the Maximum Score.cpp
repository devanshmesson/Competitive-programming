//https://leetcode.com/problems/get-the-maximum-score/
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) 
    { 
      const long long int mod=1e9+7;
      int n=nums1.size();
      int m=nums2.size();
      int i=0, j=0;
      long long int sum1=0,sum2=0;
      long long int ans=0;
      while(i<n && j<m)
      {
         if(nums1[i]<nums2[j])
         {
           sum1+=nums1[i];
           i++;
         }
         else if(nums1[i]>nums2[j])
         {
            sum2+=nums2[j];
            j++;
         }
         else
         {
             ans+=max(sum1,sum2)+nums1[i];
             sum1=0;
             sum2=0;
             i++,j++;
         }
      }
      while(i<n){sum1+=nums1[i];i++;}
      while(j<m){sum2+=nums2[j];j++;}
      ans+=max(sum1,sum2);
      return ans%mod;
      
      
    }
};
