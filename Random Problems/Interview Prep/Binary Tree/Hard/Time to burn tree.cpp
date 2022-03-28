//https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

/*
Very similar to Nodes at a distance k problem.
run a bfs.
TC- O(N)
SC-O(N)
*/
#include<bits/stdc++.h>
void find_parent(BinaryTreeNode<int> *root, map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&parent, int start, BinaryTreeNode<int> **startnode)
{
   if(root->data==start){*startnode=root;}
   if(root->left){find_parent(root->left,parent,start,startnode); parent[root->left]=root;}
   if(root->right){find_parent(root->right,parent,start,startnode); parent[root->right]=root;}
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
       BinaryTreeNode<int> *startnode;
       map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>parent;
       map<BinaryTreeNode<int>*, bool>visit;
       parent[root]=NULL;
       find_parent(root,parent,start,&startnode);
       queue<BinaryTreeNode<int>*>q;
       q.push(startnode);
       visit[startnode]=true;
       int ans=0;
       while(!q.empty())
       {
           ans++;
           int size=q.size();
           for(int i=0;i<size;i++)
           {
               BinaryTreeNode<int> *node=q.front();
               q.pop();
               if(parent[node] && !visit[parent[node]]){q.push(parent[node]); visit[parent[node]]=true; }
               if(node->left && !visit[node->left]){q.push(node->left); visit[node->left]=true;}
               if(node->right && !visit[node->right]){q.push(node->right); visit[node->right]=true;}
           }
       }
       return ans-1;
}
