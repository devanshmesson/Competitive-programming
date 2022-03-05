//https://leetcode.com/problems/string-without-aaa-or-bbb/
class Solution {
public:
    string strWithout3a3b(int a, int b) 
    {
        int n=a+b;
        string ans="";
        int turn;
        if(a>b)turn=0;
        else turn=1;
        while(a!=b)
        {
          if(turn==0)
          {
              a--;
              ans+='a';
              if(a>b){ a--; ans+='a';}
              turn=1;
          }
          else if(turn==1)
          {
              b--;
              ans+='b';
              if(b>a){b--; ans+='b';}
              turn=0;
          }
        }
        string add="ab";
        if(ans.size()>0)
        {
         if(ans[ans.size()-1]=='a')add="ba";
         else if(ans[ans.size()-1]=='b')add="ab";
        }
        
        
        if(a==b && a>0)for(int i=0;i<(a);i++)ans+=add;
        return ans;
         

    }
};
