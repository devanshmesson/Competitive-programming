//https://leetcode.com/problems/symmetric-tree/

/*
Iterative : 
Perform Level Order traversal, at each level, check whether the values of nodes from left to
right forms a palindrome or not. If not, return false, otherwise true.

if node is null, then assume it a value that can never occur.

TC - O(N)
SC - O(N)
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

/*
Recursive : 
Observation, Imagine a tree of, 2 parents & 4 children. Mirror image is when parent1's right node =  parent 2's left node 
and parent1's left node =  parent 2's right node.
If every two parent nodes satisfy the above condition, then the tree is symmetrical.

start from root->left(root1) and root->right(root2).Traverse left subtree leftwards and right subree rightwards and 
keep on checking the value of cur node of left tree and cur node of right tree, when they backtrack after reaching NUll,
root1 will go right and root2 will go left.this will keep going on.

In general, left subtree is traversing in this manner - Root left right
In general, right subtree is traversing in this manner - Root right left.

These two trees are being traversed simultaneously.

TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    bool check_preorder(TreeNode *root1,TreeNode *root2)
    {
      if(root1==NULL || root2==NULL)return (root1==root2);
      if(root1->val!=root2->val)return false;
      bool check1=check_preorder(root1->left,root2->right);
      bool check2=check_preorder(root1->right,root2->left);
      return (check1&check2);
    }
    bool isSymmetric(TreeNode* root) 
    {
        return check_preorder(root->left,root->right);
    }
};
