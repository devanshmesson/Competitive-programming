/*
Problem Link - https://leetcode.com/problems/majority-element-ii/
Solution:1
 Count each number's occurence by running one loop to have a pointer at a specific index and another nested loop to count the number at 
 specific index in the whole array.(Bruteforce)
 Time complexity - O(n^2)
 Space complexity - O(1)
 
 Solution:2
 Sort the array and count the same adjacent elements.
 Time complexity - O(nlOGn)
 Space complexity - O(1)
 
 Solution:3
 Run a O(n) loop and increase the count of particular number by storing it as index of the array.In other words, peform hashing.
 Time complexity(Map)- O(nlOGn) | Time complexity(array)- O(n)
 Space complexity - O(n)
 
 Solution:4
 1.Perform Moore's Voting Algorithm
 2.Intuition behind this algorithm is that cancel all the minority elements(let their count be x) with "x" amount of majority elements and 
 remaining number of elements will only constitute of majority element.
 3.There can be 2 Majority elements because, 2 elements can occur more than FLOOR(N/3) times. [Floor(2.9)=2, floor matlab neeche]
 Proof of point 2:
 
 umber of majority element - a
 Number of Minority elements - b
 a+b=n
 a=6
 b=5
cancel all the minority elements(let their count be a) with "a" amount of majority elements.
 a=a-b
 a=1
 So, the left element is a, which this is the majority element, but we need to check if the majority element is occuring more than FLOOR(N/3) times.
 
 Time complexity- O(n)
 Space complexity - O(1)
 
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int element1,count1=0,element2,count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(element1==nums[i])count1++;
            else if(element2==nums[i])count2++;
            else if(count1==0)
            {
                element1=nums[i];
                count1++;
            }
            else if(count2==0)
            {
                element2=nums[i];
                count2++;
            }
            else {count1--;count2--;}
        }
        
        vector<int>ans;
        int cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==element1)cnt1++;
           else if(nums[i]==element2)cnt2++;
        }
        
        
        if(cnt1>nums.size()/3)ans.push_back(element1);
        if(cnt2>nums.size()/3)ans.push_back(element2);
        return ans;
    }
};
