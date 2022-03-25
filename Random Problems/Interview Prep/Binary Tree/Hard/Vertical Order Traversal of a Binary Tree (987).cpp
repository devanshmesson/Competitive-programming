//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*
Save the column numbers of the nodes, Push the node
(complete later)
*/
class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>>ans;
        map<int, vector<int>>column;
        map<int,int>pos;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int cnt=0;
        while(!q.empty())
        {
          cnt++;
          int size=q.size();
          for(int i=0;i<size;i++)
          {
              TreeNode *node=q.front().first;
              int col=q.front().second;
              q.pop();
              column[col].push_back(node->val);
              if(node->left)q.push({node->left,col-1});
              if(node->right)q.push({node->right,col+1});
          }
          for(auto x: column)
          {
              sort(column[x.first].begin()+pos[x.first], column[x.first].end());
              pos[x.first]=x.second.size();
          }
        }
        for(auto x: column) ans.push_back(x.second);
      return ans;  
    }
};
