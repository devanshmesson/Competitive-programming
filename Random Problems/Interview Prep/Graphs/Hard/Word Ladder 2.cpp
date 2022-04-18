//https://leetcode.com/problems/word-ladder-ii/

/*
While performing BFS, Create the path.
Push the paths in the queue. An element in the queue is a path.

While exploring, Push the adjacent node in the existing path.
if the adjacent node is the endWord, then push this path in the answer.
else push the path in the queue.

Define a minimum level when we first time reached the endword, which tells the shortest length of the path.
and to assign minimum level, we need to have another variable level, which is the length of the current path.

If current path's size is >= minimum_level, then end the BFS, because, the future paths will also be >=minimum_level.

TC - O(N*M) * O(N*M) Secod term can up and down. N is number of words and M is length of each word.
SC - >O(N*M)

*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>present;
        for(int i=0;i<wordList.size();i++)present.insert(wordList[i]);
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({beginWord});
        int level=1,min_level=INT_MAX;
        
        while(!q.empty())
        {
          vector<string>path=q.front();
          q.pop();
          string node=path.back();
          if(path.size()>=min_level)break;
          if(path.size()>level)level=path.size();
          
          //Erase the present node from the wordlist because, the future nodes wont have an edge with this node. Instead, this node will have 
          //an edge with a future node.
          present.erase(node);
          for(int i=0;i<node.size();i++)
          {
            char orig=node[i];
            for(char j='a';j<='z';j++)
            {
              node[i]=j;
              if(present.find(node)!=present.end())
              {
                  path.push_back(node);
                  if(node==endWord)
                  {
                    min_level=level+1;
                    ans.push_back(path);
                  }
                  else q.push(path);
                  //for next iterations, path should be the original one.
                  path.pop_back();
              }
              node[i]=orig;
            }
          }
        }
        return ans;
        
    }
};
