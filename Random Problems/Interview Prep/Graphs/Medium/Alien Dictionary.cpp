//https://practice.geeksforgeeks.org/problems/alien-dictionary/1/?page=1&company[]=Microsoft&category[]=Graph&sortBy=submissions#
class Solution
{
    public:
    stack<char>toposort;
    int dfs(int node, int *visit, vector<int> *adj)
    {
        for(int i=0;i<adj[node].size();i++)
        {
          int adjacent=adj[node][i];
          if(visit[adjacent]==0)
          {
            visit[adjacent]=1;
            dfs(adjacent,visit,adj);
          }
        }
        toposort.push(node+'a');
    }
    string findOrder(string dict[], int N, int K) 
    {
        vector<int>adj[K];
        //Making of adjacency list
        for(int i=0;i<N-1;i++)
        {
          string first=dict[i];
          string sec=dict[i+1];
          int len1=first.size(),len2=sec.size();
          int j=0;
          while(j<len1 && j<len2)
          {
             if(first[j]!=sec[j])
             {
                 adj[first[j]-'a'].push_back(sec[j]-'a');
                 break;
             }
             j++;
          }
        }
        //Toposort using DFS
        int visit[K]={0};
        for(int i=0;i<K;i++)
        {
           if(visit[i]==0)
           {
               visit[i]=1;
               dfs(i,visit,adj);
           }
        }
        //Printing the sequence
        string sequence="";
        int added[K]={0};
        while(!toposort.empty())
        {
          char alpha;
          alpha=toposort.top();
          added[alpha-'a']=1;
          sequence.push_back(alpha);
          toposort.pop();
        }
        
        for(int i=0;i<K;i++)
        {
          if(added[i]==0)sequence.push_back(i); 
        }
        return sequence;
    }
};
