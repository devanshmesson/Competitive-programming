/*
Problem Link - https://leetcode.com/problems/search-a-2d-matrix/
Solution:1 Traverse the whole matrix and find the element.
Time complexity - O(n*m)

Solution:2 Traverse each row or column and binary search on target element.
Time complexity - O(NLogM) OR O(MLogN)

Solution:3 

Observation:
1. Find the ith row in which the element could be present, then find the jth column in the ith row to know where the element exactly is.
2. Binary search on the 1st column and find the greatest ith element which is smaller than or equal to target element."i" is the index of the row.
3. Binary searc on the ith row and find the target element.

Time complexity - O(LogN + LogM)

*/
class Solution {
public:
    
    int lower_bound(vector<vector<int>>&matrix,int *target)
    {
        int n=matrix.size();
        int low=0,high=n-1,mid=(low+high)/2,flag=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(mid>0 && matrix[mid][0]>*target)high=mid-1;
            else if(*target==matrix[mid][0])break;
            else if(mid<n-1 && matrix[mid][0]<*target)low=mid+1;
            else break;
        }
        
        if(matrix[mid][0]>*target && mid>0)mid--;
        
        return mid;
        
    }
     int binary_search(vector<int>&matrix,int *target)
     {
        
        int n=matrix.size();
        int low=0,high=n-1,mid=(low+high)/2,flag=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(mid>0 && matrix[mid]>*target)high=mid-1;
            else if(*target==matrix[mid])break;
            else if(mid<n-1 && matrix[mid]<*target)low=mid+1;
            else break;
        }
        if(matrix[mid]>*target && mid>0)mid--;
        return mid;
     }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row=lower_bound(matrix,&target);
        int col=binary_search(matrix[row],&target);
        if(matrix[row][col]==target)return true;
        else return false;
        
    }
};
