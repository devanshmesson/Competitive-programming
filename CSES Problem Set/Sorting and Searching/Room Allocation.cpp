/*
Question -minimum rooms if one person's departure time is less than next person's arrival time(these two guys will have same room)
Solved - O(nlogn) Time Complexity
Approach-Used Minimum Priority Queue to store a tuple containing departure time and room no. and compared departure time 
         with the current person's arrival time in multiset.
        -Multiset contains key as tuple containing arrival time and departure time and value as order in which the input is given.
*/
#include<bits/stdc++.h>
using namespace std;


typedef tuple<int,int>tupple;                              //tuple containing arrival and departure time

int main()
{
  int n,a,b,room=0,k=1;
  cin>>n;
  map<int,int>ans;
  multimap<tuple<int,int>,int>m;                            //multimap of tuple
  priority_queue<tupple,vector<tupple>,greater<tupple>>pq;  //min priority queue of tuple
  
  for(int i=0;i<n;i++) 
  {
    cin>>a>>b;
    m.insert({{a,b},i});
  }

  for(auto it=m.begin();it!=m.end();it++)
  {
    int ariv,del;
    tie(ariv,del)=it->first;  

    if(pq.empty() || (get<0>(pq.top())) >=ariv) // get<0>pq.top() means extracting minumum departure time till now and comparing it with arriving time
    {
      room=k;
      k++;
    }
    else
    {
      room=get<1>(pq.top());  //Alotting the same room to the current person because its ariv>depart.time in the min.priority queuee
      pq.pop();    
    }
    pq.push({del,room});            //min.priority queue contains departure time and room no. in increasing order
    ans[it->second]=room;
  }  
  cout<<--k<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<ans[i]<<" ";
  }

}
