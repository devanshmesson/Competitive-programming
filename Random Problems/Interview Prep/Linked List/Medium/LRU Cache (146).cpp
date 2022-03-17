//https://leetcode.com/problems/lru-cache/
class LRUCache 
{
public:
    struct node
    {
      int key;
      int val;
      node *next;
      node *prev;
      node(int key1,int value)
      {
         key=key1;
         val=value;
         next=NULL;
         prev=NULL;
      }
    };
    //To avoid NULL checks, I have added head and tail.
    //head's next will be the most recent used key.
    //tail's prev will be the least recently used key.
    node *head= new node(1,1);
    node *tail=new node(1,1);
    int cap;
    unordered_map<int, node*>address;
    //helper function to remove node from doubly linked list
    void removenode(node *oldnode)
    {
     oldnode->prev->next=oldnode->next;
     oldnode->next->prev=oldnode->prev;
    }
    //helper function to add node after the head of doubly linked list
    void addnode(node *newnode)
    {
      newnode->next=head->next;
      head->next->prev=newnode;
      head->next=newnode;
      newnode->prev=head;
    }
    LRUCache(int capacity) 
    {
      cap=capacity;
      head->next=tail;
      tail->prev=head;
    }
    int get(int key) 
    {
      if(address.find(key)!=address.end())
      {
         node* oldnode=address[key];
         //Removing the node from doubly linked list
         removenode(oldnode); 
         //Adding after the head
         addnode(oldnode);
         return address[key]->val;
      }
      return -1;
    }
    
    void put(int key, int value) 
    {
      node* resnode;
      int size=address.size();
      if(address.find(key)!=address.end())
      { 
         resnode=address[key];
         //Updating the value of the node
         resnode->val=value;
         //Removing the node from doubly linked list
         removenode(resnode);  
      }
      else if(size<cap) resnode=new node(key,value);
      else if(size==cap)
      {
         //Removing the Least recently used key (tail's previous)
         node* lru=tail->prev;
         address.erase(lru->key);
         removenode(lru); 
         //Adding after the head
         resnode=new node(key, value);
      }
      //Adding the node after head
      addnode(resnode);
      //Updating the address of added node(for else-if conditions)
      address[key]=resnode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
