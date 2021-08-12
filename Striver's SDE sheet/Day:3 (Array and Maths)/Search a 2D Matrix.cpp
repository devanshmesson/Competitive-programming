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
