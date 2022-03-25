//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*
Save the column numbers of the nodes, Push the node of ith column number to ith vector of "column" vector.
After the traversal of a particular row, if there were multiple elements being pushed in the same column, Then
sort the recently added elements.To do this, take anther map named "pos", which will store the starting position of
the recently added elements for all columns.so, sort from (pos[column number])th index of "column" vector till the end of "column" vector.

TC - O(N*LOG(N)) , because loop 2(highlighed) will take NLogN time after completion of level order traversal
SC - O(N)
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
          for(auto x: column) //Loop 2
          {
              sort(column[x.first].begin()+pos[x.first], column[x.first].end());
              pos[x.first]=x.second.size();
          }
        }
        for(auto x: column) ans.push_back(x.second);
      return ans;  
    }
};
