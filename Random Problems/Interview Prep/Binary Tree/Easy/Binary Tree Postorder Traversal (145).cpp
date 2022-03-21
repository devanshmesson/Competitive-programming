//https://leetcode.com/problems/binary-tree-postorder-traversal/

//Recursive
class Solution {
public:
    vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root==NULL)return ans;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};

/*
Start from root, keep going to the left, when a node's(say, n) left is NULL, its time to go to the right of n, which will be done through the else 
condition, If right(say r) is not Null, now its time to go to left of r(Repeat from start). Else if r is NULL, its time to print n and remove n
,if n was a left node of its parent(say p), then it means that p's left subtree is completed, now its time to traverse p's right subtree, which will be
done through else condition in the next iteration(it will go to else condition in the next iteration because n's left node is still NULL),Now repeat above
steps of else consition).If n was a right node of its parent(p), then it means, that p's left as well as right subtree has been traversed, so, print p 
and remove p, if p was a right child of its parent, repeat the steps till the node is not a right child.
*/

class Solution {
public:
   
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>s;
        TreeNode *leftnode=root, *rightnode;
        while(1)
        {
          if(leftnode)
          {
             s.push(leftnode);
             leftnode=leftnode->left;
          }
          else 
          {
              rightnode=s.top()->right;
              if(rightnode)leftnode=rightnode;
              else
              {
                  ans.push_back(s.top()->val);
                  rightnode=s.top();
                  s.pop();
                  //if rightnode is not the top's right node, then it means that rightnode is now a
                  //left node for its parent node, which means that, rightnode's parent should go
                  //to its right, which will be done in the next iteration(else), as leftnode is NULL.
                  while(!s.empty() && s.top()->right==rightnode)
                  {
                      ans.push_back(s.top()->val);
                      rightnode=s.top();
                      s.pop();
                  }
                  if(s.empty())break;
              }
          }
        }
        return ans;
    }
};
