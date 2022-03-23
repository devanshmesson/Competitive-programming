//https://leetcode.com/problems/same-tree/
/*
Do any traversal simulataneously for both trees, if current nodes' values are not same, then return false.
If one tree reaches NULL, while other isn't, then return false;
otherwise return true

//Below code is a preorder traversal
*/
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
       if(p==NULL || q==NULL)return (p==q);
       if(p->val!=q->val)return false;
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
