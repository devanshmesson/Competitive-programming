//https://leetcode.com/problems/binary-tree-right-side-view/

/*
Iterative
Did a level order traversal, and stored the last node each row.
TC - O(N)
SC-O(N)
*/
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int rightmost;
        while(!q.empty())
        {
          int size=q.size();
          for(int i=0;i<size;i++)
          {
              TreeNode *node=q.front();
              q.pop();
              rightmost=node->val;
              if(node->left)q.push(node->left);
              if(node->right)q.push(node->right);
          }
          ans.push_back(rightmost);
        }
        return ans; 
        
    }
};



/*
Recursive
Recursively called the right node each time, then called the left node, so every time, rightmost node for each level will be called first.
We will check if current level (0 based indexing)of node is equal to size of vector, if yes, then push this rightmost node.
TC - O(N)
SC-O(N)
*/
class Solution 
{
public:
    void rightside(TreeNode* root, vector<int>&ans, int level)
    {
        if(level==ans.size())ans.push_back(root->val);
        if(root->right)rightside(root->right,ans,level+1);
        if(root->left)rightside(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)return ans;
        rightside(root,ans,0);
        return ans; 
        
    }
};
