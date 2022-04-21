//https://practice.geeksforgeeks.org/problems/word-boggle4143/1/?page=1&status[]=unsolved&company[]=Microsoft&category[]=Graph&sortBy=submissions#
/*
Performed Backtracking through recursion.
Store all the occurrences of each letter in the grid in an unordered map.
Iterated through each word, Traverse through each occurence of first letter of the current word and 
perform backtracking.

let x=number of occurrences of first letter of current word
let len-length of current word
let N is the number of words.
TC - O(N*x*(8^len))
(8^len) is the Time complexity of recursion.
SC - O(ROWS * COLUMNS)
*/
class Solution 
{
public:
    int rows,cols;
    bool check(int x,int y)
    {
        if(x>=0 && y>=0 && x<rows && y<cols)return true;
        return false;
    }
    bool find_word_dfs(string &word, int index, vector<vector<int>> &visit,vector<pair<int,int>>directions,vector<vector<char> >& board,int curx,int cury)
    {
       if(index>=word.size())return true;
       for(int i=0;i<directions.size();i++)
       {
          int newx=curx+directions[i].first;
          int newy=cury+directions[i].second;
          if(check(newx,newy) && visit[newx][newy]==0 && word[index]==board[newx][newy] && check(newx,newy))
          {
             visit[newx][newy]=1;
             bool found=find_word_dfs(word,index+1,visit,directions,board,newx,newy);
             if(found==true)return true;
             visit[newx][newy]=0;
          }
       }
       return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) 
	{
	   map<int,vector<pair<int,int>>>present;
	   vector<string>ans;
	   rows=board.size(),cols=board[0].size();
	   vector<vector<int>>visit(rows,vector<int>(cols));
	   for(int i=0;i<rows;i++)
	   {
	    for(int j=0;j<cols;j++)
	    {
	      int index;
	      if(board[i][j]>='a' && board[i][j]<='z')index=board[i][j]-'a';
	      else index=board[i][j]-'A';
	      present[index].push_back({i,j});
	    }
	   }
	   vector<pair<int,int>>directions={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
     //Iterate for each word
	   for(int i=0;i<dictionary.size();i++)
	   {
	     string word=dictionary[i];
	     vector<vector<int>>visit(rows,vector<int>(cols));
	     int ind;
       if(word[0]>='a' && word[0]<='z')ind=word[0]-'a';
	     else ind=word[0]-'A';
       //Iterate through all occurrences of first letter of the current word 
	     for(int i=0;i<present[ind].size();i++)
	     {
	        int x=present[ind][i].first;
          int y=present[ind][i].second;
          visit[x][y]=1;
          //Run a DFS(Trying all the possible paths)
	        bool found=find_word_dfs(word,1,visit,directions,board,x,y);
	        if(found){ans.push_back(word); break;}
	        visit[x][y]=0;
	     }
	   }
	   return ans;
	   
	}
};
