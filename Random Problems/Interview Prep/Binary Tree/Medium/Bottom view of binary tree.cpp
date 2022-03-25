//https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

/*
Logic is exactly same as top view.Only change is, we are looking at the bottomost occurence of node for each column.
So, perform a level order traversal, just keep on updating the new value for the column as we go downwards.

TC -O(NLOGN)
SC -O(N)
*/
vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int>ans;
  if(root==NULL)return ans;
  map<int,int>viewed;
  queue<pair<BinaryTreeNode<int>*,int>>q;
  q.push({root,0});
  while(!q.empty())
  {
      int size=q.size();
      for(int i=0;i<size;i++)
      {
          BinaryTreeNode<int>* node=q.front().first;
          int column=q.front().second;
          q.pop();
          viewed[column]=node->data;
          if(node->left)q.push({node->left,column-1});
          if(node->right)q.push({node->right,column+1});
      }
  }
  for(auto x: viewed)ans.push_back(x.second);
  return ans; 
    
}
