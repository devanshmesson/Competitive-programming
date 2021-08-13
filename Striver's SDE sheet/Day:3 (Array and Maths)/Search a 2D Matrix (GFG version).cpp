/*
Problem link - https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

Solution:1 Traverse the whole matrix and find the element.
Time complexity - O(n*m)

Solution:2 Traverse each row or column and binary search on target element.
Time complexity - O(NLogM) OR O(MLogN)

Solution:3 
1.Idea is to reduce the time complexity by removing a row or column in each comparison until an element is found.
2.Start searching the element from top-right corner of the matrix.

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
