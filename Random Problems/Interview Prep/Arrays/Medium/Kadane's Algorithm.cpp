//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1/?page=1&company[]=Microsoft&category[]=Arrays&sortBy=submissions
/*
keep summing the elements, and keep track of max sum.
If sum gets negative then re-initialise sum to 0. This way we are trying another subarray.
TC-O(N)
SC - O(1)
*/
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
          sum+=arr[i];
          maxi=max(maxi,sum);, 
          //this line should come after maxi, because if all are negative then maxi 
          //should take the negative numbers too.
          if(sum<0)sum=0;
        }
        return maxi;
    }
};
