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
TreeNode<int>* traverse_for_leaf(TreeNode<int>*cur)
{
    if(cur==NULL)return NULL;
    TreeNode<int>*l=traverse_for_leaf(cur->left);
    TreeNode<int>*r=traverse_for_leaf(cur->right);
    if(l==NULL && r==NULL){ans.push_back(cur->data);}
    return cur;
}
int traverse_right(TreeNode<int>*cur)
{
    if(cur!=NULL && (cur->left!=NULL || cur->right!=NULL))temp.push_back(cur->data);
    else return 0;
    if(cur->right)traverse_right(cur->right);
    else traverse_right(cur->left); 
    return 0;
}
int traverse_left(TreeNode<int>*cur)
{
    if(cur!=NULL && (cur->left!=NULL || cur->right!=NULL))ans.push_back(cur->data);
    else return 0;
    if(cur->left)traverse_left(cur->left);
    else traverse_left(cur->right);
    return 0;
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
    int sz=temp.size();
    for(int i=0,j=sz-1;i<j;i++,j--)
    {
        int ex=temp[i];
        temp[i]=temp[j];
        temp[j]=ex;
    }
    for(auto x: temp)ans.push_back(x);
    return ans;
}
