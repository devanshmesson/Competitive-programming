class Solution 
{
public:
    bool cantransform(string a, string b)
    {
      int diff=0;
      for(int i=0;i<a.size();i++)
      {
         if(a[i]!=b[i])diff++;
      }
      if(diff==1)return true;
      return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
      queue<pair<string,int>>q;
      unordered_map<string, vector<string>>adj;
      wordList.push_back(beginWord);
      int n=wordList.size();
      for(int i=0;i<n;i++)
      {
         for(int j=i+1;j<n;j++)
         {
             if(cantransform(wordList[i],wordList[j]))
             {
                 adj[wordList[i]].push_back(wordList[j]);
                 adj[wordList[j]].push_back(wordList[i]);
                 
             }
         }
      }
      q.push({beginWord,1});
      unordered_map<string,bool>visit;
      visit[beginWord]=true;
      while(!q.empty())
      {
          string node=q.front().first;
          int distance=q.front().second;
          q.pop();
          
          if(node==endWord)
          {
              return distance;
              break;
          }
          for(int i=0;i<adj[node].size();i++)
          {
             string adjacent=adj[node][i];
             if(visit[adjacent]==false)
             {
                visit[adjacent]=true;
                q.push({adjacent,distance+1});
             }
          }
      }
      return 0;
    }
};
