//https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
class Solution {
public:
    int minimumSum(int num) 
    {
         int n=num;
  vector<int>v;
  while(n>0)
  {
    int k=n%10;
    n/=10;
    v.push_back(k);
  }
  sort(v.begin(),v.end());

  int a,b;
  a=v[3]+(v[0]*10);
  b=v[2]+(v[1]*10);
  return a+b;
    }
};
