/*
Problem link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

Solution 1 : O(n^3) approach [Bruteforce]
Generate all (n)*(n+1)/2 subsets.~ O(n^2)
iterate each substring and check if there is any repeated character by using array[256]. ~O(n)
Total time complexity - O(n^2) * O(n) = O(n^3)
-------------------------------------------------
Solution 2 : O(n^2) [Bruteforce]
generate all (n)*(n+1)/2 subsets. ~ O(n^2)
Sum the numbers while generating them and keeping track of the repeated number. O(1)
Total time complexity - O(n^2) * O(n) = O(n^2)
------------------------------------------------
Solution:3
1.Initialize a left pointer and right pointer. basically it signifies the range(left to right).left=0
2.Right pointer will be the current index in the loop.
3.Traverse the array and on each index, check whether this element is present in the frequency array or not by checking the hash value of the element(1 or 0), while traversing,
hash the element with value=1 at the end of the loop.
4.If hash value of element is 0, count++.
5.If hash value of element is 1, this means the element is repeated between left pointer and right pointer,so increase the left pointer one by one and do this until 
the element is not repeated.While incrementing left pointer unhash the elements with value=0 which has index < left index because now, those elements are not in consideration
and change the count value to right-left+1.
6.return the maximum count.

Time complexity - O(2n) because left pointer will maximum traverse till right pointer, so at max, total iterations will be 2*n.
Space complexity - O(256), range of 256 characters will be there in the input array, so we are just hashing it's ascii value.

------------------------------------------------------------
Solution:4
Idea of solution:4 is same as solution:3, but some optimizations in terms of time are done through observations.
Observation is, element is repeated when the element at old index is in between left pointer and right pointer and the element gets no repetition as soon as 
left pointer is ahead of old index of the repeated element.This means if we know the old index of the element, left pointer can be jumped straighaway to old index+1 instead of 
incrementing it one by one and checking the repetition at each step.So instead of storing the presence of element in frequency array, store it's last index so that
left pointer can be jumped to old index+1 in constant time.

Observation 2 is, there is no need of unhashing the elements when the left pointer is jumped, we can do it in a smarter way by knowing the fact that, 
if suppose there is an element 'x' between left pointer and right pointer and if it's hash value (old index) is less than the left pointer, then it means that 
'x' is not repeated because the old index of x is not between the left pointer and right pointer.So, if old index is not between left pointer and right pointer, 
consider it as unhashed and increase the counter.

Time complexity - O(n) because left pointer will jump at a certain index in constant time.
Space complexity - O(256), range of 256 characters will be there in the input array, so we are just hashing it's ascii value.



*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int a[256]={0},n=s.size(),maxi=0,count=0,left=0;
        memset(a,-1,sizeof(a));
        for(int i=0;i<n;i++)
        {
            if(a[s[i]]>=left)
            {
                count=i-a[s[i]];
                left=a[s[i]]+1;
                a[s[i]]=i;
            }
            else 
            {
                a[s[i]]=i;
                count++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};
