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
        ListNode *mininode=NULL;
        int minival=INT_MAX, minindex;
        for(int i=0;i<k;i++)
        {
            if(lists[i]==NULL)continue;
            if(minival>lists[i]->val)
            {
                minival=lists[i]->val;
                mininode=lists[i];
                minindex=i;
            }
        }
        if(mininode==NULL)break;
        tail->next=mininode;
        tail=tail->next;
        lists[minindex]=lists[minindex]->next;
      }
      return head->next;
    }
};

