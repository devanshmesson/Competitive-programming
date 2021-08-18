/*
Problem - https://leetcode.com/problems/4sum/
Solution:1
Run 4 nested loops through 4 pointers(i,j,k,l) and sum the elements at those positions and check whether it's equal to target or not.
Time complexity - O(n^4)

Solution:2
Sort the array
Run 3 nested loop through 3 pointers(i,j,k) and find (target-a[i]-a[j]-a[k]) through binary search in the array from (k+1)th index to last index.
O(n^3 * LogN)

Solution:3
Sort the array
Run 2 nested loops through 2 pointers(i,j) and find the other 2 elements which sum to (target-a[i]-a[j]) through 2 pointer approach.This 2 pointer approch will only work if array is sorted.

Demonstration of 2 pointer approach - 

Example array - 1 2 6 7 10 
Find 2 elements which sum to 14.
left pointer=0, right pointer=4
a[left pointer] + a[right pointer]=10
Because the sum is small, we need to add big elements, so we increase left pointer.
left pointer=1,right pointer=4
a[left pointer] + a[right pointer]=12
Because the sum is small, we need to add big elements, so we increase left pointer.
left pointer=2,right pointer=4
a[left pointer] + a[right pointer]=16
Because the sum is big, we need to add small elements, so we decrease right pointer.
left pointer=2,right pointer=3
a[left pointer] + a[right pointer]=14
Now, sum=target, so elements are at indexes 2 and 3.

2 pointer approach is O(n).

Important:
To find 







*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n=nums.size(),temp;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(n<4)return ans;
        for(int i=0;i<n-3;)
        {
            for(int j=i+1;j<n-2;)
            {
                int left=j+1,right=n-1,targ=target-nums[i]-nums[j];
                int sum=nums[left]+nums[right];
                
               while(left<right)
               {
                    
                   sum=nums[left]+nums[right];
                    if(sum>targ)
                    {
                     temp=right-1;
                     while(temp>j && nums[temp]==nums[right])temp--;
                     right=temp;
                    }
                    else if(sum<targ)
                    {
                     temp=left+1;
                     while(temp<n-1 && nums[temp]==nums[left])temp++;
                     left=temp;
                    }
                    else 
                    {
                        vector<int>quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[left]);
                        quad.push_back(nums[right]);
                        ans.push_back(quad);
    
                        temp=right-1;
                        while(temp>j+1 && nums[temp]==nums[right])temp--;
                        right=temp;
                        temp=left+1;
                        while(temp<n-1 && nums[temp]==nums[left])temp++;
                        left=temp;
                    }
               }
                
                temp=j+1;
                while(temp<n-1 && nums[temp]==nums[j])temp++;
                j=temp;
            }
                temp=i+1;
                while(temp<n-1 && nums[temp]==nums[i])temp++;
                i=temp; 
        }
        return ans;
    }
};
