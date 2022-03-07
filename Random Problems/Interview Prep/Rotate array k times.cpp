/*
link - https://leetcode.com/problems/rotate-array/
*/

/*
Approach - 1
Shift the array by 1, and do this operation k%n times

Time complexity - O(N^2)
Space complexity - O(1)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int skip = k%n;
       
        for(int i=0;i<skip;i++)
        {
          int last=nums[n-1];
          for(int j=n-2;j>=0;j--)
          {
              nums[j+1]=nums[j];
          }
          nums[0]=last;
        }
        
        
    }
};
/*
Approach - 2
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
