//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*
If both the nodes is less than the root, then go to root's left.
Else If both the nodes is greater than the root, then go to root's right.
Else the root is the LCA.
How? because if you now go to root's left, then the bigger node will not exist in root's left subtree, because the bigger node means bigger than the root.
Similarly,  if you now go to root's right, then the smaller node will not exist in root's right subtree, because the smaller node means smaller than the root.

TC - O(Height of BST)
SC - O(1)

*/
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while(root)
        {
           if(p->val>root->val && q->val>root->val)root=root->right;
           else if(p->val<root->val && q->val<root->val)root=root->left;
           else return root;
        }
        return root;
    }
};
