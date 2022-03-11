//https://leetcode.com/problems/rotate-list/

/*
 Approach 1 
 TC - O( (K%N) * N) 
 SC - O(1)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
      if(head==NULL || head->next==NULL || k==0)return head;
      int len=0;
      ListNode *cur=head;
      ListNode *last, *secondlast;
      //Compute length of list
      while(cur!=NULL){cur=cur->next; len++;}
      cur=head;
      k=k%len; //Not including this line, will lead to TLE
      //Rotating k times
      while(k--)
      {
        while(cur!=NULL)
        {
          //Find Second last node
          if(cur->next!=NULL) if(cur->next->next==NULL)secondlast=cur;
          cur=cur->next;
        }
        last=secondlast->next;
        //Connect last node to head.
        last->next=head;
        //Making second_last node as last node.
        secondlast->next=NULL; 
        //Making last node as head 
        head=last;
        //Retaining cur to head again, for next iteration
        cur=head;
      }
      return head;
    }
};

/*
Approach 2
 TC - O(N) 
 SC - O(1)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
      if(head==NULL || head->next==NULL)return head;
      int len=0;
      ListNode* tail=head, *cur=head;
      while(cur!=NULL)
      {
          tail=cur;
          cur=cur->next;
          len++;
      }
      tail->next=head;
      int skip=k%len;
      
      skip=len-skip-1;
      while(head!=NULL && skip>0)
      {
        head=head->next;
        skip--;
      }
      cur=head->next;
      head->next=NULL;
      return cur;   
    }
};
