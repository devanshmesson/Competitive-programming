class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int neg=0,z=0;
        for(auto x:nums)neg+=(x<0),z+=(x==0);
        if(z>0)return 0;
        if(!(neg&1))return 1;
        return -1;   
    }
};
