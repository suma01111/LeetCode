//NODE Classs
class Node {
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    // insert right after head
    void insertNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    // remove node from DLL
    void deleteNode(Node* newNode) {
        Node* prevNode = newNode->prev;
        Node* nextNode = newNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        int ans = node->value;

        deleteNode(node);
        insertNode(node);

        return ans;
    }

    void put(int key, int value) {
        // key already exists
        if(mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            deleteNode(existing);
            existing->value = value;
            insertNode(existing);
            return;
        }

        // cache full
        if(mp.size() == cap) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        insertNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */