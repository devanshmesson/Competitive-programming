/*
link - https://leetcode.com/problems/rotate-array/
*/
/*
Approach - 1
Take another vector 'v' and store ith element of nums array at [(i+k)%n]th index of v;
Time complexity - O(N)
Space complexity - O(N)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
          v[(i+k)%n]=nums[i];
        }
        nums=v;
    }
};
