//https://leetcode.com/problems/binary-tree-maximum-path-sum/
/*
1)The answer will always exists in a left subree or a right subtree of a particular node. (a straight path)
2)The answer can also be left subtree + right subtree + node of which these subtrees are. (umbrella path)

Start from root, go to left as well as right, if left is giving a negative value, we should not consider it, so assign left to 0.Similarly for right as well. 
Think this in a way, that there is no benefit in adding a negative sum to the ans.

Because we have solved the negative value issue. Now left and right subtree always gives either 0 or a positive value.

For every node, we are calculating, left subtree + right subtree + node of which these subtrees are. The maximum among all is the answer.
How to calculate the values of left and right subtree?

Either you take a left subtree + center or you take a right subtree + center and return max value out of the two to parent node.Basically,
we are trying all the paths, and on every node, we calculating the umbrella path. If left subtree or right subtree or both gets negative, then it becomes 
a straight path. So return the maximum path value among all the the nodes.

*/

class Solution 
{
public:
    int maxi=INT_MIN;
    int maxpath(TreeNode* root)
    {
        if(root==NULL)return 0;
        int left=max(0,maxpath(root->left));
        int right=max(0,maxpath(root->right));
        int center=root->val;
        maxi=max(maxi,left+right+center);
        return center+max(left,right);
    }
    int maxPathSum(TreeNode* root) 
    {
       if(root==NULL)return 0;
       maxpath(root);
       return maxi;
    }
};
