//https://leetcode.com/problems/merge-two-sorted-lists/

/*
Two pointer approach
Put one pointer(i) to list1 and another pointer(j) to list2.
if value at i < value at j:  add this node to the ans and increment i.
else add this node to the ans and increment j.

if the traversal of any of two linked list ends, add the rest of the elements of another list to the ans.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      if(list1==NULL && list2==NULL)return NULL;
      ListNode* headans;
      ListNode* tailans;
     
      
      int flag=0;
    
      
      while(list1!=NULL && list2!=NULL)
      {
        if(list1->val < list2->val)
        {
          if(flag==0)
          {
              tailans=list1;
              headans=list1;
              flag=1;
          }
          else 
          {
              tailans->next=list1;
              tailans=tailans->next;
          }
          list1=list1->next;
        }
        else
        {
          if(flag==0)
          {
              headans=list2;
              tailans=list2;
              flag=1;
          }
          else 
          {
              tailans->next=list2;
              tailans=tailans->next;
          }
          list2=list2->next;
        }
      }
        
      while(list1!=NULL)
      {
        if(flag==0)
        {
            tailans=list1;
            flag=1;
        }
        else 
        {
         tailans->next=list1;
         tailans=tailans->next;
        }
        list1=list1->next;
      }
      while(list2!=NULL)
      {
         if(flag==0)
         {
            tailans=list2;
            flag=1;
         }
         else 
         {
          tailans->next=list2;
          tailans=tailans->next;
         }
        list2=list2->next;
      }
      return headans;
    }
};
