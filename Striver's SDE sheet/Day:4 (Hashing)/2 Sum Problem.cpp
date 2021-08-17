/*
Problem Link - https://leetcode.com/problems/two-sum/
Solution:1
For every element check if there exits (target-element) in the array.
Time complexity - O(n^2)
Space complexity - O(1)

Solution:2
Store every element as a key in the unordered_map and store the value it's index and check whether (target-element) is in the map or not.In other words, perform hashing.
Time complexity - O(n)
Space complexity - O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
            }
            mp[nums[i]]=i;
        }
        return ans;
        
    }
};
