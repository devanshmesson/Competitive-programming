//https://leetcode.com/problems/clone-graph/

/*
Perform DFS on the given tree, and as we reach a node, clone this node by making 
a new node and make its adjacency list by recursively calling the dfs again and after the dfs call for 
the adjacent node gets over, we will have our completely cloned adjacent node along with its neighbors.

TC - O(N+E)*LOG(N) IF We unordered map then no log n factor will be there.
SC - O(N)
*/
Node *dfs(Node *node, map<Node*,Node*>&tellnode)
{
  //cloning the current node
  Node *newnode=new Node(node->val);
  //storing the cloned node
  tellnode[node]=newnode;
  //Making the adjacency list
  for(int i=0;i<(node->neighbors).size();i++)
  {
    Node *adjacent=(node->neighbors)[i];
    if(tellnode.find(adjacent)==tellnode.end())
    {
       Node *adjnode=dfs(adjacent,tellnode);
       //Pushing in the adjacency list
       (newnode->neighbors).push_back(adjnode);
    }
    else
    {
      (newnode->neighbors).push_back(tellnode[adjacent]);
    }
    
  }
  return newnode;
}

class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
      if(node==NULL)return NULL;
      map<Node*,Node*>tellnode;
      return dfs(node, tellnode); 
    }
};
