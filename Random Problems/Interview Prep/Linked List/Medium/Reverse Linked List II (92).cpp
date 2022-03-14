//https://leetcode.com/problems/reverse-linked-list-ii/

//Approach 1
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head==NULL || head->next==NULL || left==right)return head;
        
        ListNode* prevleftptr=NULL;
        if(left==2)prevleftptr=head;
        //moving a pointer to left position
        ListNode *leftptr=head;
        int traverse=left-1;
        while(leftptr!=NULL && traverse>0)
        {leftptr=leftptr->next;traverse--; if(traverse==1)prevleftptr=leftptr;}
        
        //moving a pointer to right position
        ListNode *rightptr=head;
        traverse=right-1;
        while(rightptr!=NULL && traverse>0){rightptr=rightptr->next;traverse--;}        
        
        //Reversing the list in range left,right
        ListNode* dummy=NULL, *cur=leftptr, *adj=leftptr->next;
        ListNode* rightptrnext=rightptr->next;
        while(cur!=rightptrnext)
        {
          cur->next=dummy;
          //moving dummy, cur, adj to one step ahead.
          dummy=cur;
          cur=adj;
          if(adj!=NULL)adj=adj->next;
        }
        
        leftptr->next=rightptrnext;
        if(prevleftptr!=NULL)prevleftptr->next=rightptr;
                
        if(left==1)return rightptr;
        return head;
        
    }
};

//Approach 2

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
      if(head==NULL && head->next==NULL || left==right)return head;
      ListNode* dummy=new ListNode();
      dummy->next=head;
      ListNode *pre=dummy, *cur, *adj, *rightptr=dummy; 
      //Making pre point to previous node of (left)th node.
      for(int i=0;i<left-1;i++)pre=pre->next;
      //Making rightptr point to (right)th node
      for(int i=0;i<right;i++)rightptr=rightptr->next;
      cur=pre->next;
      adj=cur->next;
      for(int i=left;i<=right;i++)
      {
        //if cur is (left)th node, it should point to next of (right)th node.
        if(cur==pre->next)cur->next=(rightptr->next);
        else
        {
          //Putting cur node in between pre and pre->next.
          cur->next=pre->next;
          pre->next=cur;
        }
        cur=adj;
        if(adj!=NULL)adj=adj->next;
      }
      if(left==1)return rightptr;
      return head;
    }
};
