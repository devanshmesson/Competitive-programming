//https://practice.geeksforgeeks.org/problems/e47329920b4e75869ea7b0e9b7c59ea145ccc22c/1/#


/*
Create an adjacency list of police, each police's list has theifs which can be caught, they are in range of k.
Bactrack all the possibilities and find the maximum number of visited theifs.
 
Let t= number of theifs in each police list
let p= number of police
TC - O(t^p) each police has t possibilities.
SC - O(N)
*/
class Solution
{
    public:
    int max_catch=0,ans=0;
    int find_theives(vector<int> *pt, int *visit, vector<int> &police, int p)
    {
        if(p>=police.size())return max_catch;
        for(int i=0;i<pt[police[p]].size();i++)
        {
          int theif=pt[police[p]][i];  
          if(visit[theif]==0)
          {
            ans++;
            max_catch=max(max_catch,ans);
            visit[theif]=1;
            find_theives(pt,visit,police,p+1);
            visit[theif]=0;
            ans--;
          }
        }
        return max_catch;
    }
    int catchThieves(char arr[], int n, int k) 
    {
      int visit[n]={0};
      vector<int>pt[n+1];
      vector<int>police;
      for(int i=0;i<n;i++)
      {
         if(arr[i]=='P')
         {
           police.push_back(i);
           for(int j=(i-k);j<=(i+k);j++)
           {
              if(j<0 || j>=n)continue;
              if(arr[j]=='T')pt[i].push_back(j);
           }
         }
      }
      int p=0;
      int y=find_theives(pt,visit,police,p);
      return y;
    }
};
/*
1.Save indexes of police and theif in 2 arrays, one for police and one for theif.
2.Take two pointers, p=0 and t=0, and iterate police array with p and theif array with t.
3.If theif[t] is out of range of police[p] and theif[t] is on the left side of police, then the police[p] 
cannot catch him, and all police on right side cant also catch him, so, increase the pointer of theif. ie. t++

4. If theif[t] is out of range of police[p] and theif[t] is on the right side of police, then the police[p] 
cannot catch him, but police on the right of police[p] may catch him, so increase the pointer of police. ie p++ 

TC - O(N) each police has t possibilities.
SC - O(N)
*/
class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
      vector<int>police,theif;
      for(int i=0;i<n;i++)
      {
        if(arr[i]=='P')police.push_back(i);
        else theif.push_back(i);
      }
      int p=0,t=0, caught=0;
      while(p<(police.size()) && t<(theif.size()))
      {
        if((theif[t]>=(police[p]-k) && theif[t]<=police[p]) || (theif[t]>=police[p] && theif[t]<=(police[p]+k))){t++; p++; caught++;}
        if(theif[t]<(police[p]-k))t++;
        else if(theif[t]>(police[p]+k))p++;
      }
      return caught;
    }
};

/*
Same approach, Same TC BUT IN O(1) Space.
*/

class Solution
{
    public:
    int next_police(int &p, char *arr, int n)
    {
      p++;
      int i;
      for(i=p;i<n;i++)
      {
       if(arr[i]=='P')break;   
      }
      p=i;
    }
    int next_theif(int &t, char *arr, int n)
    {
      t++;
      int i;
      for(i=t;i<n;i++)
      {
       if(arr[i]=='T')break;   
      }
      t=i;
    }
    int catchThieves(char arr[], int n, int k) 
    {
      int p=INT_MAX,t=INT_MAX, caught=0;
      for(int i=0;i<n;i++)if(arr[i]=='P'){p=i; break;}
      for(int i=0;i<n;i++)if(arr[i]=='T'){t=i; break;}
      while(p<n && t<n)
      {
        if(t>=(p-k) && t<=p || t>=p && t<=(p+k))
        {
         next_police(p,arr,n);
         next_theif(t,arr,n);
         caught++;
        }
        if(t<(p-k))next_theif(t,arr,n);
        else if(t>(p+k))next_police(p,arr,n);
      }
      return caught;
    }
};
