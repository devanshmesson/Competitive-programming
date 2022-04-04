//https://practice.geeksforgeeks.org/problems/largest-bst/1/#

/*
If cur->val > [the node with maximum value on the left subtree of cur] & [cur->val < the node with minimum value on the right subtree of cur]
then Its a BST starting with root ans size becomes size of left subtree +  size of right subtree + 1(cur itself).
return this bst with maximum,minimum value among its subtrees and the updated size.

else its not a BST, so obviously none of its ancestors will be BST, so now, we have to ensure that
the if condition should get a false for each ancestor, because, there will be NO BST above this node.
so, return Maximum value as INT_MAX and minimum value as INT_MIN, and return the max of sizes of the two subtrees, This will
reach till root of whole tree and it will finally return the max of two subtrees, if in case "else" satisfies for a node below the root of whole tree.

TC - O(N)
SC -O(N) RECURSION.


*/
class Solution
{
  public:
  vector<int> maxbst(Node *root)
  {
    if(!root)return {INT_MIN,INT_MAX,0};
    vector<int>left_info=maxbst(root->left);
    vector<int>right_info=maxbst(root->right);
    if(root->data > left_info[0] && root->data < right_info[1])
    {
        int size=left_info[2]+right_info[2]+1;
        int maxi=max(root->data,right_info[0]);
        int mini=min(root->data,left_info[1]);
        return {maxi,mini,size};
    }
    else return {INT_MAX,INT_MIN,max(left_info[2],right_info[2])};
  }
  int largestBst(Node *root)
  {
    return maxbst(root)[2]; 
  }
};
