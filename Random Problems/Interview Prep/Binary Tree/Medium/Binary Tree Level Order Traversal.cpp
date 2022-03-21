//https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
          int size=q.size();
          temp.clear();
          for(int i=0;i<size;i++)
          {
            TreeNode *curnode=q.front();
            int val=curnode->val;
            q.pop();
            if(curnode->left)q.push(curnode->left);
            if(curnode->right)q.push(curnode->right);
            temp.push_back(val);
          }
          ans.push_back(temp);
        }
        return ans;
    }
};
