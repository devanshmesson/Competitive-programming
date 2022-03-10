//https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
Approach 1
TC-O(N+M)
SC-O(N+M)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)return NULL;
        map<ListNode*,int>mp;
        while(headA!=NULL)
        {
            mp[headA]=1;
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            if(mp[headB]==1)return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

/*
Approach 2
TC-O(N+M)
SC-O(1)
*/
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)return NULL;
        int len1=0,len2=0;
        ListNode *trav=headA;
        while(trav!=NULL){len1++; trav=trav->next;}
        trav=headB;
        while(trav!=NULL){len2++; trav=trav->next;}
        
        ListNode *travnode;
        if(len1>len2){trav=headA;travnode=headB;}
        else {trav=headB;travnode=headA;}
        
        if(trav==travnode)return trav;
      
        int diff=abs(len1-len2);
        while(trav!=NULL)
        {
          diff--;
          trav=trav->next;          
          if(diff<0)travnode=travnode->next;
          if(trav==travnode)return trav;
        }
        return NULL;
    }
};
