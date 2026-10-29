class Node {
public: 
    int key; 
    int value; 
    Node* prev; 
    Node* next; 

    Node (int key, int value) {
        this->key = key; 
        this->value = value; 
        prev = nullptr; 
        next = nullptr;  
    }
};

class LRUCache {
public:
    Node* right; 
    Node* left;
    unordered_map<int, Node*> cache;  
    int capacity; 

    LRUCache(int capacity) {
        right = new Node(0, 0); 
        left = new Node(0, 0);
        right->prev = left; 
        left->next = right; 
        this->capacity = capacity; 
        cache.clear(); 
    }

    void add(Node* node) {
        Node* next = right->prev;
        next->next = node; 
        
        node->prev = next;
        node->next = right; 
         
        right->prev = node;  
    }

    void remove(Node* node) {
        Node* nextNode = node->next; 
        Node* prevNode = node->prev; 
        prevNode->next = nextNode; 
        nextNode->prev = prevNode; 
    }

    int get(int key) {

       if (cache.count(key)) {
        remove(cache[key]);
        add(cache[key]); 
        return cache[key]->value; 
       } 

       return -1; 
    }
    
    void put(int key, int value) {

        if (cache.count(key)) remove(cache[key]);
        cache[key] = new Node(key, value);

        add(cache[key]);

        if (cache.size() > capacity) {
            Node* removeNode = left->next; 

            remove(removeNode);
            cache.erase(removeNode->key);
            delete removeNode; 
        }
    }
};
