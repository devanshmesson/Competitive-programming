/*
Problem link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)

Problem in my words :  Given two sorted arrays, merge them and sort the array.But the sorted array must be represented as
divided into those 2 arrays.Extra space is not permitted. 

For example : 
Array1: 1 2 10
Array2: 3 6 7

Output:
Array1: 1 2 3
Array2: 6 7 10

Solution:

Observation : In order to have the expected output, last element(i) of array1 should be smaller that first element(j) of array2
1.Start with i of array1 and j of array2.If arr1[i] > arr2[j] , swap them and decrement i and increment j;
2.As the rest of the part in both arrays are already sorted.Continue 1st step.
3.If If arr1[i] <= arr2[j] break the loop.This means all the required elements in array1 and array2 are present

Why are we ignoring the numbers that are swapped and moving ahead?
- Because when arr2[j] came into arr1 array, this element will not be checked again with any element becuase the rest of the elements in array2 are sorted.
  This means that rest of the elements in array2 are bigger than arr2[j](swapped)

-Because when arr1[i] came into arr2 array, this element will not be checked again with any element because the rest of the elements in array1 are sorted.
  This means that rest of the elements in array1 are smaller than arr1[i](swapped).


*/

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int i=n-1,j=0;
    while(i>=0 && j<=m-1)
    {
        if(arr1[i] > arr2[j])
        {
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }
        else break;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
} 
