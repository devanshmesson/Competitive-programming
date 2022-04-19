//https://practice.geeksforgeeks.org/problems/minimum-swaps/1/?page=1&status[]=unsolved&company[]=Microsoft&category[]=Graph&sortBy=submissions#

/*
Hash the elements of the given array.
Copy the given array into another array and sorted it.

Now compare the ith element of given array(nums) and sorted array.
If they are same, do nothing.
If not, then swap nums[a] and nums[b],
where a = position of (element of sorted array at ith position) in the nums array. This info will be stored in a map.
      b = ith position
Also, swap the positions in map.
      
TC - O(N*Log(N))
SC - O(N)
*/
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   vector<int>sorted=nums;
	   sort(sorted.begin(),sorted.end());
	   int n=nums.size();
	   unordered_map<int,int>pos;
	   for(int i=0;i<n;i++)pos[nums[i]]=i;
	   int minswap=0;
	   for(int i=0;i<n;i++)
	   {
	       if(nums[i]==sorted[i])continue;
	       int pos1=pos[sorted[i]];
	       int pos2=i;
	       swap(pos[nums[i]],pos[sorted[i]]);
	       swap(nums[pos1],nums[pos2]);
	       minswap++;
	   }
	   return minswap;
	    
	    
	    
	}
};
