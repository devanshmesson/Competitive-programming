/*
Problem Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

Solution:1
Perform bruteforce by checking every pair of elements and counting the inversions.
Time complexity - O(n^2)

Solution:2
1.This can be efficiently solved by divide and conquer using merge sort algorithm.
2.Inversions can be counted during the merging stage of merge sort algorithm.
3.During merging stage, the array is divided into 2 parts. left part of the array and right part of the array.
4.Observation is that, Indexes of the elements of the right array are greater than the indexes of the elements of the left array.
5.This is where we are improving the time complexity, during merging, if element of right array(let say, x) is smaller than element of left array(let say, it's index in left array is i), then this is an inversion,
because the element at right array has index greater than the index of the element of left array.
6.left array and right array are already sorted(inc order),so, x is also smaller than the elements which have indexes greater than i in the left array. So total inversions will be from ith element to last element.
of left array.

For example -  Array:    2 4 1 8 5 3
                           /     \
                      (2 4 1)    (8 5 3) inversions=1(3<4)  [left array and right array will be changed as: (1 2 4) and (3 5 8)]
                      / \         /  \
                     (2) (4 1)   (8) (5 3) inversions=1(1<4) | inversions=2(3<8, 5<8) [left array and right array will be changed as: (2 )(1 4) and (8) (3 5)]
                           / \         / \
                         (4)  (1)     (5) (3)
                   inversions=1(1<4)   inversions=1(3<5)
Total inversions = 6

Time complxity - O(NLogN) ,  LogN for dividing the array and N for merging the left array and right array.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  
   long long int merge(long long low,long long mid,long long high,long long int *arr)
    {
        long long left[mid-low+1],right[high-mid],index1=0,index2=0,inversion_count=0;
        for(long long i=low;i<=mid;i++){left[index1]=arr[i];index1++;}
        for(long long i=mid+1;i<=high;i++){right[index2]=arr[i];index2++;}
    
        
        long long int ptr1=0,ptr2=0,index3=low;
        
        while(ptr1<index1 && ptr2<index2)
        {
            if(right[ptr2]<left[ptr1])
            {
                inversion_count+=index1-1-ptr1+1;
                arr[index3]=right[ptr2];
                ptr2++;
                
            }
            else 
            {
                arr[index3]=left[ptr1];
                ptr1++;
            }
            index3++;
        }
        while(ptr1<index1){arr[index3]=left[ptr1];ptr1++;index3++;}
        while(ptr2<index2){arr[index3]=right[ptr2];ptr2++;index3++;}
        return inversion_count;
    }
    long long  merge_sort(long long low,long long high,long long int *arr)
    {
       long long int inversion_count=0;
        if(low<high)
        {
            long long mid=(low+high)/2;
            inversion_count+=merge_sort(low,mid,arr);
            inversion_count+=merge_sort(mid+1,high,arr);
            inversion_count+=merge(low,mid,high,arr);
        }
        return inversion_count;
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        long long int inversion_count=merge_sort(0,N-1,arr);
        return inversion_count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
