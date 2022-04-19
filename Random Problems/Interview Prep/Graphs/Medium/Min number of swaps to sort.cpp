//https://practice.geeksforgeeks.org/problems/minimum-swaps/1/?page=1&status[]=unsolved&company[]=Microsoft&category[]=Graph&sortBy=submissions#

/*
Answer will be the number of cycles in the array.
These cycle will always be non-intersecting.

If an element p is at x position, and it was supposed to be at y position.
and at y position, an element q is present which was supposed to be at z position.
and at z position, element s is present, which was supposed to be at x position.
and at x position, p is present.

Therefore its a cycle.
Number of swaps needed to get these elements back to their right place is cycle length -1.

So, just detect all the cycles and sum the required swaps of all the cycles.

TC - O(N*Log(N))
SC - O(N)



*/
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   vector<pair<int,int>>sorted;
	   int n=nums.size();
	   for(int i=0;i<n;i++)sorted.push_back({nums[i],i});
	   sort(sorted.begin(),sorted.end());
	   int visit[n]={0};
	   unordered_map<int,int>pos;
	   for(int i=0;i<n;i++)pos[sorted[i].second]=i;
	   int minswap=0;
	   for(int i=0;i<n;i++)
	   {
	     if(i==sorted[i].second || visit[i]==1)continue;
	     int cur=i;
	     while(visit[cur]==0)
	     {
	        visit[cur]=1;
	        minswap++;
	        //sorted[cur].first is standing at sorted[cur].second index,
	        //but it was supoosed to be standing at cur index.On which some
	        //other element is standing, to go at that element's index, visit pos[cur] 
	        cur=pos[cur];
	     }
	     //cycle length -1 
	     minswap--;
	   }
	   return minswap; 
	}
};
