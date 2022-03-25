//https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

/*
TC -O(N*LOG(N))
SC- O(N)
Concept of vertical view of tree is same as this one.
perform level order traversal, store the first occurrence of node of each column.
Level order traversal works because, we have to store the topmost occurence of node for each column.
*/
vector<int> getTopView(TreeNode<int> *root) 
{
  vector<int>ans;
  if(root==NULL)return ans;
  map<int,int>viewed;
  queue<pair<TreeNode<int>*,int>>q;
  q.push({root,0});
  while(!q.empty())
  {
      int size=q.size();
      for(int i=0;i<size;i++)
      {
          TreeNode<int>* node=q.front().first;
          int column=q.front().second;
          q.pop();
          if(viewed.find(column)==viewed.end())viewed[column]=node->val;
          if(node->left)q.push({node->left,column-1});
          if(node->right)q.push({node->right,column+1});
      }
  }
  for(auto x: viewed)ans.push_back(x.second);
  return ans; 
}
