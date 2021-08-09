/*
Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Solution:1
Check every pair and maximize the difference.
Time complexity - O(n^2)

Solution:2
1.Find the minimum element by traversing each element in the array and also, maximize the difference between current element and minimum element.4
Time complexity - O(n)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini=INT_MAX,profit=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mini)mini=prices[i];
            else profit=max(profit,prices[i]-mini);
        }
        if(profit==INT_MIN)profit=0;
        return profit; 
    }
};
