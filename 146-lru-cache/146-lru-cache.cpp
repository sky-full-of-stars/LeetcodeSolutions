class LRUCache 
{
public:
    class Node
    {
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int key, int val)
            {
                this->key = key;
                this->val = val;
            }
    };
    
    int capacity;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    map<int, Node*> mp;
    
    void addNode(Node* newNode)
    {
        Node* nextNode = head->next;
        nextNode->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nextNode;
    }
    
    void deleteNode(Node* delNode)
    {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        delete(delNode);
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if(mp.find(key) != mp.end())
        {
            Node* presentNode = mp[key];
            int val = presentNode->val;
            deleteNode(presentNode);
            //mp.erase(key);
            addNode(new Node(key,val));
            mp[key] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key) != mp.end())
        {
            Node* pos = mp[key];
            //mp.erase(key);
            deleteNode(pos);
        }
        else
        {
            if(mp.size() == capacity)
            {
                int leastUsedKey = tail->prev->key;
                mp.erase(leastUsedKey);
                deleteNode(tail->prev);
            }
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */