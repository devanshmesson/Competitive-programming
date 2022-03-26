//https://leetcode.com/problems/symmetric-tree/

/*
complete it
*/
class Solution 
{
public:
    bool is_palindrome(vector<int>&ans)
    {
      int n=ans.size();
      for(int i=0,j=n-1;i<j;i++,j--)if(ans[i]!=ans[j])return false;
      return true;
    }
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>ans;
            for(int i=0;i<size;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                if(node==NULL){ans.push_back(-200); continue;}
                if(node!=root)ans.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if(ans.size()==0)continue;
            if(!is_palindrome(ans) || ans.size()<2)return false;
        }
        return true;
        
    }
};
