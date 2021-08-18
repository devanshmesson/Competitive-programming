/*
Problem link - https://www.interviewbit.com/problems/subarray-with-given-xor/
Let given xor be XR.

Solution 1 : O(n^3) approach [Bruteforce]
Generate all (n)*(n+1)/2 subsets.~ O(n^2)
iterate each subset and xor the elements to check if the xor is equal to XR or not. ~O(n)
Total time complexity - O(n^2) * O(n) = O(n^3)
-------------------------------------------------
Solution 2 : O(n^2) [Bruteforce]
generate all (n)*(n+1)/2 subsets. ~ O(n^2)
Sum the numbers while generating them and keeping track the xor. O(1)
Total time complexity - O(n^2) * O(n) = O(n^2)
-------------------------------------------------
Solution:3
1.Idea is that if A is the xor of subarray[0 to i] and B is xor of the subarray[0 to j] and let xor1 be the xor of subarray[i+1 to j].(Here, i<j)
So, B=A ^ xor1.Let the pointer is at j, and xor of the subarray[0 to j] is A ^ xor1, To check whether xor1==XR, we xor "A ^ xor1" with XR, if result is A, that means 
xor of subarray[i+1 to j] = XR, so count this as a subarray.

if A ^ xor1 ^ XR == A, This means that xor of subarray[i+1 to j] = given xor(XR), i.e. xor1=XR.

1.Make prefix XOR array of the input array.
2.Traverse the prefix xor array, assume the current element index as j, if a[j]==XR, this means xor of subarray[0 to j] = XR, so count this subarray.
3.Assume that there is an element at ith index(i<j) and assume that a[j]=a[i]^(xor1,where xor1=XR).xor1 is the xor of subarray[i+1 to j] of the input array.Assuming xor1=XR.
4.To check in reality, whether xor1==XR or not, a[j]^XR, should be equal to a[i].if thats the case, count the number of a[i] which is stored in the unordered map.
5.Return count.

(ye tune khud solve ki thi, paper pe example leke kario, you will understand, idea is taken from Largest subarray with 0 sum.cpp)

Time complexity - O(n)
Space Complexity - O(n).
*/
int Solution::solve(vector<int> &A, int B)
{
    int n=A.size();
    for(int i=1;i<n;i++)A[i]^=A[i-1];
    unordered_map<int,int>mp;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==B){count++;}
        int xor1=A[i]^B;
        if(mp.find(xor1)!=mp.end())count+=mp[xor1];
        mp[A[i]]++;
    }
    return count;
}
