//https://practice.geeksforgeeks.org/problems/digit-multiplier3000/1/
class Solution {
  public:
    string getSmallest(long long N) 
    {
        int i;
        bool ok=false;
        string ans="";
        if(N<10){ans.push_back((char)N+48);return ans;}
       
        while(N>1)
        {
            for(i=9;i>=1;i--)
            {
             if(N%i==0){N/=i;break;}
            }
            ans.push_back((char)i+48);
            if(i==1){ok=true;break;}
        }
        sort(ans.begin(),ans.end());
        if(ok)return "-1";
        return ans;
    }
};

