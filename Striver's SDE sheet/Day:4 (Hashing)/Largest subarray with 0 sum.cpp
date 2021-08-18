/*
Problem Link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

Solution 1 : O(n^3) approach [Bruteforce]
Generate all (n)*(n+1)/2 subsets.~ O(n^2)
iterate each subset and sum the elements to check if the sum is 0 or not. ~O(n)
Total time complexity - O(n^2) * O(n) = O(n^3)
-------------------------------------------------
Solution 2 : O(n^2) [Bruteforce]
generate all (n)*(n+1)/2 subsets. ~ O(n^2)
Sum the numbers while generating them and keeping track the sum. O(1)
Total time complexity - O(n^2) * O(n) = O(n^2)
------------------------------------------------
Solution:3 
1.Idea is to create a prefix sum array.
2.If the sum(S) up to ith index is repeated again at jth index, it means that:
sum of subarray(0 to i)index = S
sum of subarray((i+1) to j)index=0
that's why sum of subarray(0-j)=S.

3.So, if an element in the prefix sum array is repeated again, we subtract the previous index(index at which the sum was found the first time) from the current index(index at which the sum was found the latest time). 
Previous index will be stored in an unordered map. 

Time complexity - O(n)
Space complexity - O(n)


*/

int maxLen(int A[], int n)
{
    int maxi=0,subarray_count;
    unordered_map<int,int>mp;
    for(int i=1;i<n;i++)A[i]+=A[i-1];
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)maxi=max(maxi,i+1);
        else if(mp.find(A[i])!=mp.end())
        {
          subarray_count=i-mp[A[i]];
          maxi=max(maxi,subarray_count);
        }
        else mp[A[i]]=i;
    }
    
    return maxi;
}
