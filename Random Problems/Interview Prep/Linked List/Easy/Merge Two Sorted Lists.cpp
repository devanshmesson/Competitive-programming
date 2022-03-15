//https://leetcode.com/problems/merge-two-sorted-lists/

/*
Approach -1 
Time complexity - O(n+m)
Space Complexity - O(n+m)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      if(list1==NULL && list2==NULL)return NULL;
      if(list1==NULL && list2!=NULL)return list2;
      if(list2==NULL && list1!=NULL)return list1;
      ListNode* tailans=new ListNode;
      ListNode* headans=tailans;
      
      while(list1!=NULL && list2!=NULL)
      {
        if(list1->val < list2->val)
        {
         tailans->next=new ListNode(list1->val);
         list1=list1->next;
        }
        else
        {
          tailans->next=new ListNode(list2->val);
          list2=list2->next;
        }
        tailans=tailans->next;
      }
      while(list1!=NULL)
      {
         tailans->next=new ListNode(list1->val);
         tailans=tailans->next;
         list1=list1->next;
      }
      while(list2!=NULL)
      {
        tailans->next=new ListNode(list2->val);
        tailans=tailans->next;
        list2=list2->next;
      }
      return headans->next;
    }
};

/*
Approach - 2
Same as two pointer approach, but here, Instead of making a new linkedlist, and I am just changing the links between the input lists.

Time complexity - O(n+m)
Space Complexity - O(1)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      if(list1==NULL && list2==NULL)return NULL;
      if(list1==NULL && list2!=NULL)return list2;
      if(list2==NULL && list1!=NULL)return list1;
      ListNode* tail=new ListNode();
      ListNode* head=tail;
      while(list1!=NULL && list2!=NULL)
      {
        if(list1->val < list2->val)
        {
         tail->next=list1;
         list1=list1->next;
        }
        else
        {
          tail->next=list2;
          list2=list2->next;
        }
        tail=tail->next;
      }
      tail->next=list1!=NULL?list1:list2;
      return head->next;
    }
};

