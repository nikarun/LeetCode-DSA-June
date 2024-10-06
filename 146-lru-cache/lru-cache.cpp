class Node{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int _key,int _value){
        key=_key;
        value=_value;
    }
};
Node *head=new Node(-1,-1);
Node *tail = new Node(-1,-1);
unordered_map<int,Node*>mp;
int cap;

class LRUCache {
public:
    // always add new node after head & remove node before tail
    void addNode(Node *new_node){
        Node *temp=head->next;
        head->next=new_node;
        temp->prev=new_node;
        new_node->next=temp;
        new_node->prev=head;
    } 

    void deleteNode(Node *delete_node){
        Node *left=delete_node->prev;
        Node *right = delete_node->next;
        left->next=right;
        right->prev=left;
        
    }
    LRUCache(int capacity) {
        mp.clear();
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *ptr=mp[key];
            cout<<ptr->key<<endl;
            deleteNode(ptr);
   
            addNode(ptr);
            mp[key]= head->next;
            cout<<head->next->value<<endl;
            return head->next->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }
        if(mp.size()==cap){
            Node *ptr=tail->prev;
            mp.erase(ptr->key);
            deleteNode(ptr);
        }
        addNode(new Node(key,value));
        mp[key]= head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */