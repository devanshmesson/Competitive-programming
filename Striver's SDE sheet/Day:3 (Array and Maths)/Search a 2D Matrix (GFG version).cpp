/*
Problem link - https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

Solution:1 Traverse the whole matrix and find the element.
Time complexity - O(n*m)

Solution:2 Traverse each row or column and binary search on target element.
Time complexity - O(NLogM) OR O(MLogN)

Solution:3 
1.Idea is to reduce the time complexity by removing a row or column in each comparison until an element(X) is found.
2.Start searching the element from top-right corner of the matrix.
3.If X > current element, this means the element is not present in the entire row because all elements are smaller than X, so move to next row.
4.If X < current element, this means the element is not present in the entire column because all elements are greater than X, so move to previous column.
5.If X == current element, this means, X is found, so stop here!

Why are we starting our search from top-right corner?
-Because by starting from top right corner, we are able to remove the row/column where the element cannot exist due the condition given, which eventually reduces the size of matrix and 
element is searched in the remaining part of tha matrix.

Relate this approach to binary search - (Refer this  - https://www.youtube.com/watch?v=VS0BcOiKaGI)
by starting from top-right corner, we have two choices to go:
1.Down (same column,next row)
2.Left (Same row,previous column)

By Going downwards, elements >= current element are present and by Going left, elements <= current element are present.
So, just like binary search we compare the current element with X : 
if X > current element, go downwards and remove the row where the current element exists.
if X < current element, go left and remove the column where the current element exists.
if X == current element stop.


What will happen if we start our search from top-left corner?
-We will not be able to remove the row/column where the element cannot exist due the condition given, So we have to traverse all rows and columns to find X.


Time complexity - O(m+n), because i must be less than n and j must be greater than 0 as we are doing i++ and j - -.
So at max, m+n comparisons can be done.

Case when m+n comparisons are done:
When the target element is located at bottom left of matrix and you start from top right of the matrix.


*/
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int j=M-1,i=0,ans=0;
	    while(i<N && j>=0)
	    { 
	        if(X==mat[i][j]){ans=1;break;}
	        else if(X>mat[i][j])i++;
	        else if(X<mat[i][j])j--;
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}  // } Driver Code Ends
