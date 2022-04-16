//https://practice.geeksforgeeks.org/problems/alien-dictionary/1/?page=1&company[]=Microsoft&category[]=Graph&sortBy=submissions#

/*
Performed Topological Sort here.
We are given some strings, which we have to consider as sorted. They are not actually sorted.
From the order in which strings are placed, we have to print the alphabetical order
of the characters in terms of how it is sorted.



We will first compare adjacent strings , and will compare the ith character of both strings.
If string1[i]!=string2[i], that means, string1[i] should come before string2[i].
This reminds us of Topo sort. So, we can create a directed graph of nodes being characters.
So, push string2[i] in the adjacency list of string1[i].Now, as soon as we found this unequal condition we will break the comparison loop because, this is a like a lexicographical 
comparison. Now we will move to next two adjacent strings and do the same.

Now we have the directed graph, perform Toposort, we will get the sequence of which comes before and which comes after.

N edges and K nodes are there at max.
TC - O(N+K)
SC - O(K)


*/
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
