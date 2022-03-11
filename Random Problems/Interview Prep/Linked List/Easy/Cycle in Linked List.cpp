// https://leetcode.com/problems/linked-list-cycle/

/*Approach -1 
Used Hashing 
Time complexity - O(n)
Space Complexity - O(n)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        map<ListNode*,int>mp;
        int ok=0;
        if(head==NULL)return false;
        while(head!=NULL)
        {
            if(mp[head]>0){ok=1;break;}
            mp[head]++;
            head=head->next;
        }
        
        if(ok==1)return true;
        else return false;
        
    }
};
//-----------------------------------------
/*Approach 2 (Floyd’s Cycle-Finding Algorithm )
Using slow pointer and fast pointer
Time complexity - O(n)
Space Complexity - O(1)
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
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL)return false;
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast)return true;
        }
        return false;
        
    }
};
