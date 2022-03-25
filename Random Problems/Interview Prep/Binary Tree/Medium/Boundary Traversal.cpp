//https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
/*
TC-O(N)
SC-O(N)

1.Traverse the boundary of left subtree exluding leaf nodes(dfs)
2.Traverse the leaf nodes (dfs).
3.Traverse the boundary of right subtree exluding leaf nodes (dfs) (Add the reversed traversal to the ans, because expected way 
of traversal was upwards.)
*/
vector<int>ans;
vector<int>temp;
bool isleaf(TreeNode<int>*cur){return (cur->left==NULL && cur->right==NULL);}
TreeNode<int>* traverse_for_leaf(TreeNode<int>*cur)
{
    if(cur==NULL)return NULL;
    TreeNode<int>*l=traverse_for_leaf(cur->left);
    TreeNode<int>*r=traverse_for_leaf(cur->right);
    if(l==NULL && r==NULL){ans.push_back(cur->data);}
    return cur;
}
void traverse_right(TreeNode<int>*cur)
{
    while(cur && !isleaf(cur))
    {
      temp.push_back(cur->data);
      if(cur->right)cur=cur->right;
      else cur=cur->left;   
    }
    //Add the reversed temp vector into ans vector
    for(int i=temp.size()-1;i>=0;i--) ans.push_back(temp[i]);
}
void traverse_left(TreeNode<int>*cur)
{
    while(cur && !isleaf(cur))
    {
      ans.push_back(cur->data);
      if(cur->left)cur=cur->left;
      else cur=cur->right;   
    }
}
vector<int> traverseBoundary(TreeNode<int>* root)
{
    ans.clear();
    temp.clear();
    ans.push_back(root->data);
    if(root->left==NULL && root->right==NULL){return ans;}
    traverse_left(root->left);
    traverse_for_leaf(root);
    traverse_right(root->right);
    return ans;
}
