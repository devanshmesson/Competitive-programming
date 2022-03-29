//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/*
Serializing a tree means encoding the tree into a string format.
Deserializig a tree means decoding the encoded string to the binary tree.

Given a binary tree, encode it, return the encoded binary tree in the form of string.
Now, Decode this encoded string and Build the binary tree and return the builded binary tree.

Solution :
To encode it, perform a level order traversal, save this traversal into a string. If a node is NULL, save it as "#".

To decode it, Take the first value from the string, convert it to integer, and Make a node with this value as the root.
Push this node in the queue.

Now, Take the node situated at front of the queue(newnode), and take the next two values from the string, and attach the first value 
to newnode's left(make a node with first value and attach it to left of newnode)  and attach the second to newnode's right
(make a node with second value and attach it to right of newnode).
Push the newnode's left node and right node to queue. and repeat.

Basically, we are make the tree levelwise.

TC -O(N)
SC -O(N)

*/
class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
      string encode="";
      if(!root){return "";}
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty())
      {
          int size=q.size();
          for(int i=0;i<size;i++)
          {
              TreeNode *node=q.front();
              q.pop();
              
              encode+=node?to_string(node->val):"#";
              encode+=",";
              if(!node)continue;
              q.push(node->left);
              q.push(node->right);
          }
      }
      return encode;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
      if(data.size()==0)return NULL;
      queue<TreeNode*>q;
      stringstream values(data);
      string getval;
      //Till first comma, copy the characters to getval string.
      getline(values,getval,',');
      //now, getval contains the first value.
      TreeNode *root, *newnode;
      root=newnode=new TreeNode(stoi(getval));
      q.push(newnode);
      while(!q.empty())
      {
          //Taking next two values and attaching the first to newnode's left and attaching the second to newnode's right
          newnode=q.front();
          q.pop();
          getline(values,getval,',');
          newnode->left=getval[0]=='#'?NULL:new TreeNode(stoi(getval));
          if(getval[0]!='#')q.push(newnode->left);
          getline(values,getval,',');
          newnode->right=getval[0]=='#'?NULL:new TreeNode(stoi(getval));
          if(getval[0]!='#')q.push(newnode->right);
      }
     return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
