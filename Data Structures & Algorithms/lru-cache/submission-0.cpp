class Node {
public: 
    int val; 
    int key;
    Node* prev; 
    Node* next; 

    Node(int key, int val) {
        this->key = key; 
        this->val = val; 
        prev = nullptr; 
        next = nullptr; 
    }
};

class LRUCache {
private: 
    int capacity;
    unordered_map<int, Node*> cache; 
    Node* right; 
    Node* left;

    void add(Node* node) {
        Node* recent = right->prev; 
        recent->next = node;
        node->prev = recent; 
        node->next = right; 
        right->prev = node; 
    }

    void remove(Node* node) {
        Node* behind = node->prev; 
        Node* front = node->next; 
        behind->next = front; 
        front->prev = behind; 
    } 

public:
    LRUCache(int capacity) {
        this->capacity = capacity; 
        cache.clear(); 
        right = new Node(0, 0);
        left = new Node(0, 0);
        left->next = right; 
        right->prev = left;   
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* access = cache[key];

            remove(access);
            add(access); 

            return access->val; 
        }

        return -1; 
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        } 

        Node* newNode = new Node(key, value); 
        cache[key] = newNode; 
        add(newNode);

        if (cache.size() > capacity) {
            Node* removeNode = left->next; 
            remove(removeNode); 
            cache.erase(removeNode->key); 
            delete removeNode;
        }
    }
};
