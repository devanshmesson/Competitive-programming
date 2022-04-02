//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*
Because Inorder sequence of BST is in sorted order.So, we can have another vector and copy the preorder into this and sort it.So, this will become
an inorder sequence for the BST.So, now problem boils down to generate a unique Binary tree from inorder and preorder traversal.This Binary tree will be
BST!

TC - O(N*LOGN)
SC - O(N)
*/
class Solution 
{
public:
    map<int,int>root_pos;
    TreeNode* makebst(vector<int>&preorder,int pre_start,int pre_end,int in_start,int in_end)
    {
      if(pre_start>pre_end)return NULL;
      int root_position=root_pos[preorder[pre_start]];
      int leftnodes=root_position-in_start;
      TreeNode *newnode=new TreeNode(preorder[pre_start]);
      newnode->left=makebst(preorder,pre_start+1,pre_start+leftnodes,in_start,root_position-1);
      newnode->right=makebst(preorder,pre_start+leftnodes+1,pre_end,root_position+1,in_end);
      return newnode;
      
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
       int n=preorder.size();
       vector<int>inorder;
       for(int i=0;i<n;i++)inorder.push_back(preorder[i]);
       sort(inorder.begin(),inorder.end());
       for(int i=0;i<n;i++)root_pos[inorder[i]]=i;
       int pre_start=0,pre_end=n-1,in_start=0,in_end=n-1;
       return makebst(preorder,pre_start,pre_end,in_start,in_end);
    }
};
/*
Run a DFS, Concept is of ranges. So, iterate the preorder traversal, 
If curent node's value satisfies the value range for it's parent, then it gets
attached to its parent.Otherwise, it backtracks to it's parent and so on, and when it satisfies
the value range, it gets attched to it's parent.

TC - O(N)
SC -O(N) - Recursion
*/

class Solution 
{
public:
    int ptr=0;
    TreeNode* makebst(vector<int>&preorder, int l,int r)
    {
        if(ptr>=preorder.size())return NULL;
        int value=preorder[ptr];
        if(value<=l || value>=r)return NULL;
        ptr++;
        TreeNode *newnode=new TreeNode(value);
        newnode->left=makebst(preorder,l,value);
        newnode->right=makebst(preorder,value,r);
        return newnode;  
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
       return makebst(preorder,INT_MIN,INT_MAX);
    }
};
