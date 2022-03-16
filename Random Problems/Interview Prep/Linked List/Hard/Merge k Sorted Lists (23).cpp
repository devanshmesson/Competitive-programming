//https://leetcode.com/problems/merge-k-sorted-lists/
/*
Approch 1
TC - O(N*K)
SC - O(1)
*/
class Solution 
{
public:
    ListNode* merge2list(ListNode *head1, ListNode *head2)
    {
      ListNode* tail=new ListNode();
      ListNode* head=tail;
      while(head1!=NULL && head2!=NULL)
      {
        if(head1->val < head2->val)
        {
          tail->next=head1;
          head1=head1->next;
        }
        else
        {
          tail->next=head2;
          head2=head2->next;
        }
        tail=tail->next;
      }
      tail->next=head1!=NULL?head1:head2;
      return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
      int k=lists.size();
      if(k==0)return NULL;
      if(k==1)return lists[0];
      ListNode *sorted=lists[0];
      for(int i=1;i<k;i++)
      {
        sorted=merge2list(sorted,lists[i]);
      }
      return sorted;
    }
};
/*
Approach 2
TC - (N*K)
SC- O(1)
*/
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
      int k=lists.size();
      if(k==0)return NULL;
      if(k==1)return lists[0];
      ListNode *tail=new ListNode();
      ListNode *head=tail;
      while(1)
      { 
        int minival=INT_MAX, minindex=-1;
        //Finding the next minimum value out of the k lists
        for(int i=0;i<k;i++)
        {
            if(lists[i]==NULL)continue;
            if(minival>lists[i]->val)
            {
                minival=lists[i]->val;
                minindex=i;
            }
        }
        //If traversal of all the k lists are completed.
        if(minindex==-1)break;
        //Linking the node with minimum value to previous node.
        tail->next=lists[minindex];
        //Updating the tail node
        tail=tail->next;
        //Incrementing the pointer of the list from which minimum value is fetched.
        lists[minindex]=lists[minindex]->next;
      }
      //Because first node is dummy node.
      return head->next;
    }
};

/*
Approach 3
TC - O(N * Log(K))
SC - O(K)
*/
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
      int k=lists.size();
      if(k==0)return NULL;
      if(k==1)return lists[0];
      ListNode *tail=new ListNode();
      ListNode *head=tail;
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
      for(int i=0;i<k;i++)if(lists[i])pq.push({lists[i]->val,i});
      while(!pq.empty())
      { 
        int minival=INT_MAX, minindex=-1;
        //Finding the next minimum value out of the k lists
        minival=pq.top().first;
        minindex=pq.top().second;
        pq.pop();
        //Linking the node with minimum value to previous node.
        tail->next=lists[minindex];
        //Updating the tail node
        tail=tail->next;
        //Incrementing the pointer of the list from which minimum value is fetched.
        if(lists[minindex])lists[minindex]=lists[minindex]->next;
        if(lists[minindex])pq.push({lists[minindex]->val,minindex});
      }
      //Because first node is dummy node.
      return head->next;
    }
};
/*
Approach - 4
TC - O(N * Log(K))
SC - O(1)
*/
class Solution 
{
public:
    ListNode* merge2list(ListNode *head1,ListNode* head2)
    {
        ListNode* tail=new ListNode();
        ListNode* head=tail;
        while(head1 && head2)
        {
            if(head1->val < head2->val)
            {
                tail->next=head1;
                head1=head1->next;
            }
            else 
            {
               tail->next=head2;
               head2=head2->next; 
            }
            tail=tail->next;
        }
        tail->next=head1?head1:head2;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
      int k=lists.size();
      if(k==0)return NULL;
      if(k==1)return lists[0];
      ListNode *tail=new ListNode();
      ListNode *head=tail;
      int adjacent=1;
      while(adjacent < k)
      {   
          //Merging pairs of adjacent lists and storing the result in the first list.
          //Adjacent lists are in the form of i,i+adjcent, because in the next iteration,
          //adjacent of adjacent will become the adjacent.
          //For example, 0,1,2,3 ->(0,1),(2,3)[adjacent=1]-> 0, 2 [adjacent=adjacent+adjacent=2]-> 0
          for(int i=0;i+adjacent<k;i+=(adjacent*2)) lists[i]=merge2list(lists[i],lists[i+adjacent]);
          //Making adjacent=adjacent of adjacent
          adjacent*=2;
      }
      //The result will be store in first list.
      return lists[0];
    }
};
