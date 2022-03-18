class LFUCache
{
public:
    struct node
    {
        int val, key,used;
        node* next;
        node* prev;
        node(int key_, int val_)
        {
         used=0;
         key=key_;
         val=val_;
         next=NULL;
         prev=NULL;
        }
    };
    void initialize_list(int count)
    {
        cnt[count].first=new node(1,1);
        cnt[count].second=new node(1,1);
        cnt[count].first->next=cnt[count].second;
        cnt[count].second->prev=cnt[count].first;
    }
    int cap;
    int freq=1;
    unordered_map<int,pair<node*,node*>>cnt;
    unordered_map<int, node*>address;
    void removenode(node *oldnode)
    {
     oldnode->prev->next=oldnode->next;
     oldnode->next->prev=oldnode->prev;
    }
    //helper function to add node after the head of doubly linked list
    void addnode(node *newnode, int count)
    {
      newnode->next=cnt[count].first->next;
      cnt[count].first->next->prev=newnode;
      cnt[count].first->next=newnode;
      newnode->prev=cnt[count].first;
    }
    LFUCache(int capacity) 
    {
       cap=capacity;
    }
    int get(int key) 
    {
      if(address.find(key)!=address.end() && cap>0)
      {
        int count=address[key]->used;
        removenode(address[key]);
        address[key]->used+=1;
        if(cnt[count+1].first==NULL)initialize_list(count+1);
        addnode(address[key], count+1);
        if(cnt[freq].first->next->next==NULL)freq++;
        return address[key]->val;
      }
      return -1;
    }
    void put(int key, int value) 
    { 
      if(cap==0)return;
      int size=address.size();
      node* resnode;
      if(address.find(key)!=address.end())
      {
          resnode=address[key];
          resnode->val=value;
          removenode(address[key]);
      }
      else if(size<cap)
      {
          resnode=new node(key,value);
      }
      else if(size==cap)
      {
        resnode=new node(key,value);
        address.erase(cnt[freq].second->prev->key); 
        removenode(cnt[freq].second->prev);  
      } 
      address[key]=resnode;
      int count=address[key]->used;
      address[key]->used+=1;
      if(cnt[count+1].first==NULL)initialize_list(count+1);
      addnode(resnode, count+1);
      if(count==0)freq=1;
      else if(cnt[freq].first->next->next==NULL)freq++;
    } 
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
