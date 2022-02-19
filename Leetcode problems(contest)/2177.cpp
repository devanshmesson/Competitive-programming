class Solution {
public:
    vector<long long> sumOfThree(long long num) 
    {
          
  vector<long long int>v;
  if(num%3!=0)return v;
  v.push_back((num/3)-1);
  v.push_back((num/3));
  v.push_back((num/3)+1);
  return v;
    }
};
