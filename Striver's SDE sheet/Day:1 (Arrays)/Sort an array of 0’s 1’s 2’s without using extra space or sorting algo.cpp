/*
Problem Link - https://leetcode.com/problems/sort-colors/
Required Time complexity - O(n) (use only one O(n) loop to solve the problem , O(2*n) not allowed)
Required Space Complexity - O(1)


Problem in my words -  Given an array containing 0,1,2.Sort the array

Solution - Dutch national flag algorithm will be used to solve the problem in only one O(n) loop.Counting sort method will use 2 O(n) loops.So 
Dutch national flag algorithm is an optimization of counting sort.

Dutch national flag algorithm will segregate 0 , 1 , 2 with the help of three pointers named as low , mid , high.

After segregation array will look like this:

Considering 0 based indexing.
index 0 to low-1 will have 0's
index low to high will have 1's
index high+1 to n-1 will have 2's

mid pointer is used to traverse the array.

if mid pointer founds 1 then it will move forward.
if mid pointer founds 0 then swap(arr[low] , arr[mid]) and move low and mid forward.
If mid pointer founds 2 then swap(arr[high] , arr[mid]) and move high backward.

Why we move mid pointer forward in case:2 after swap but we dont move mid pointer forward in case:3
Ans- 
This is obvious that low pointer will only contain 0 or 1.

If low contain 0 it means that low and mid pointer are standing on same place , so left will acknowledge the 0 which he swapped with mid(that 0 is not ignored).
If Low contains 1 then see case:1 , mid has to move forward.
*/

class Solution 
{
public:
    int temp; // not to make it a pointer (i was doing a mistake,to remind it i wrote it)
    void swap1(int *a,int *b){temp=*a;*a=*b;*b=temp;}
    void sortColors(vector<int>& nums) 
    {
        //Dutch national flag algorithm
        int low=0,mid=0,n=nums.size(),high=n-1;
        
        for(int i=0;i<n;i++)
        {
          if(mid>high)break;
          if(nums[mid]==1)mid++;
          else if(nums[mid]==0)
          {
              swap1(&nums[mid],&nums[low]);
              mid++;
              low++;
          }
          else if(nums[mid]==2)
          {
             swap1(&nums[mid],&nums[high]);
             high--;
          }
        }
    }
};
