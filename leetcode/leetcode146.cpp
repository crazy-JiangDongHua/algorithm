class LRUCache {
public:
    struct Node{
        int k,v;
        Node *pred, *next;
        Node():k(-1),v(-1),pred(nullptr),next(nullptr){}
        Node(int k, int v):k(k),v(v),pred(nullptr),next(nullptr){}
    }header,tailer;
    int size, capacity;
    unordered_map<int, Node*> hash;
    
    LRUCache(int capacity) {
        this->size=0;
        this->capacity=capacity;
        header.next=&tailer;
        tailer.pred=&header;
    }
    
    int get(int key) {
        if(hash.count(key)>0){
            Node* p=hash[key];
            moveNode2Header(p);
            return p->v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* p;
        if(hash.count(key)>0){
            p=hash[key];
            p->v=value;
            removeNode(p);
        }else{
            p=new Node(key, value);
            hash[key]=p;
            size++;
        }
        addNode2Header(p);
        if(size>capacity){
            p=tailer.pred;
            removeNode(p);
            hash.erase(p->k);
            delete p;
            size--;
        }
        return;
    }

    void removeNode(Node* p){
        p->pred->next = p->next;
        p->next->pred = p->pred;
    }

    void addNode2Header(Node* p){
        p->next=header.next;
        p->pred=&header;
        header.next->pred=p;
        header.next=p;
    }

    void moveNode2Header(Node* p){
        removeNode(p);
        addNode2Header(p);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */