/*
 Problem link - https://leetcode.com/problems/majority-element/
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
 
 Proof of point 2: 
 Total number of elements - n
 Number of majority element - a
 Number of Minority elements - b
 a+b=n
 a=6
 b=5
cancel all the minority elements(let their count be a) with "a" amount of majority elements.
 a=a-b
 a=1
 So, the left element is a, which this is the majority element.
 
 Time complexity- O(n)
 Space complexity - O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Moore's algorithm
        int element,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)element=nums[i];
            if(element==nums[i])count++;
            else count--;
        }
        return element;
        
        
    }
};
