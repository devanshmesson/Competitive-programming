//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/*
Find parent of every node through dfs and run a bfs from target node and perform k iterations.
after k iterations, the queue contains the nodes at a distance k from target node.

TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    void find_parent(TreeNode* root, TreeNode* target, map<TreeNode*,TreeNode*>&parent)
    {
       if(root->left){find_parent(root->left,target,parent); parent[root->left]=root;}
       if(root->right){find_parent(root->right,target,parent); parent[root->right]=root;}
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
       map<TreeNode*,TreeNode*>parent;
       map<TreeNode*, bool>visit;
       parent[root]=NULL;
       find_parent(root,target,parent);
       queue<TreeNode*>q;
       q.push(target);
       visit[target]=true;
       while(!q.empty() && k--)
       {
           int size=q.size();
           for(int i=0;i<size;i++)
           {
               TreeNode *node=q.front();
               q.pop();
               if(parent[node] && !visit[parent[node]]){q.push(parent[node]); visit[parent[node]]=true; }
               if(node->left && !visit[node->left]){q.push(node->left); visit[node->left]=true;}
               if(node->right && !visit[node->right]){q.push(node->right); visit[node->right]=true;}
           }
       }
       vector<int>ans;
       while(!q.empty()){ans.push_back(q.front()->val); q.pop();}
       return ans;
    }
};
