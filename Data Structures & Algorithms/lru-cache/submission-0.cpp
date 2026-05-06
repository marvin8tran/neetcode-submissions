class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){};
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;


    void removeNode(Node* curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    void appendNode(Node* curr){
        tail->prev->next = curr;
        curr->prev = tail->prev;
        tail->prev = curr;
        curr->next = tail;
        
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cache.clear();
    }
    
    int get(int key) {
        if(cache.count(key)){
            removeNode(cache[key]);
            appendNode(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.count(key)){
            removeNode(cache[key]);
            delete cache[key];
            cache.erase(key);
        }
        
        if(cache.size() >= cap){ 
            Node* tmp = head->next;
            removeNode(tmp);
            cache.erase(tmp->key);
            delete tmp;
        }

        Node* x = new Node(key, value);
        appendNode(x);
        cache[key] = x;

    }
};
