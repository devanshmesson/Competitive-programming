//https://leetcode.com/problems/word-ladder/

/*
Performed BFS.
This problem ask us to find the shortest path from beginword to endword.
There is an edge between two nodes, if the there is only one different letter between, The edge weight will be 1.

To find edge, Traverse each letter in the word, and substitute all 26 letters one by one, and if
the new word formed is in the unordered_set, then there is an edge between the two nodes.

just keep track of distance variable in the queue and if we are going to one node to another node increment the 
distance by 1.

TC - O(N*M)
S  - O(N*M)
*/
class Solution 
{
public:
   
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
      unordered_set<string>present;
      int n=wordList.size();
      for(int i=0;i<n;i++)
      {
        present.insert(wordList[i]);
      }
      queue<pair<string,int>>q;
      q.push({beginWord,1});
      while(!q.empty())
      {
        string node=q.front().first;
        int distance=q.front().second;
        q.pop();
        if(node==endWord)return distance;
        present.erase(node);
        for(int i=0;i<node.size();i++)
        {
          char orig=node[i];
          for(int j=0;j<26;j++)
          {
            node[i]='a'+j;
            if(present.find(node)!=present.end())q.push({node,distance+1});
          }
          node[i]=orig;
        }
      }
      return 0;
     
    }
};
