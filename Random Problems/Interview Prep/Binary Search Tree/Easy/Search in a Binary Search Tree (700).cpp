//https://leetcode.com/problems/search-in-a-binary-search-tree/

/*
If the value of the current node is equal to val, just return it.
If the value is less than the root value, go it's left
If the value is more than the root value, go it's right.

TC - O(Log N), because we will traverse at max the height of BST, which is Log N.
SC - O(1)
*/
class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
       while(root)
       {
           if(val==root->val)return root;
           if(val>root->val)root=root->right;
           else root=root->left;
       }
       return NULL;
    }
};
