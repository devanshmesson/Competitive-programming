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

/*
Approach - 3
Divide the array into skip=k%n groups and replace a[(i+skip)%n]=a[i]. Do this operation till all n elements are replaced.

Time complexity explanation
For loop will run at max n/k. There are k groups in total, SO k*(n/k) = n

Note -  There can be case when one loop runs n times, if this is a case, then this means all n elements are replaced.
So we dont goto next iteration and we break the loop.

Time complexity - O(N)
Space complexity - O(1)
*/

class Solution 
{
public:
    
    void rotate(vector<int>& nums, int k) 
    {
      int n=nums.size();
      int skip=k%n;
      //Divide n into k groups of size k/n
      int start=0;
      int cnt=0;
      while(cnt<n)
      {
        int temp=nums[start];
        int i=start;
        while(1)
        {
            int go=(skip+i)%n;
            int temp2=nums[go];
            nums[go]=temp;
            temp=temp2;
            cnt++;
            i+=skip;
            if(go==start)break;
        }
        
        start++;
      }
    }
};

/*
Approach - 4

Time complexity - O(N)
Space complexity - O(1)
*/

class Solution 
{
public:
    void reverse(int l, int r,vector<int>&nums)
    {
      for(int i=l,j=r;i<j;i++,j--)
      {
          int temp=nums[i];
          nums[i]=nums[j];
          nums[j]=temp;
      }
    }
    void rotate(vector<int>& nums, int k) 
    {
      int n=nums.size();
      int skip=k%n;
      /*
       Prefix of length=(n-skip) should become Suffix length=(n-skip).
       Suffix of length=skip should become prefix of length=skip.
       
       Order of elements should be same.
       
       To do this.
       1.Reverse the whole array
         - Reversed Prefix will become suffix and Reversed suffix will become prefix.
       2.Reverse the Suffix of length=(n-skip) of the reversed array to make it a equal to                      prefix(length = n-skip) of  original array.
       3.Reverse the Prefix of length=(skip) of the reversed array to make it a equal to suffix(length          = skip) of original array.
      */
      //Doing point 1
      reverse(0,n-1,nums);
      // Doing point 2
      reverse(skip,n-1, nums);
      //Doing point 3
      reverse(0,skip-1, nums);
      
    
    }
};
