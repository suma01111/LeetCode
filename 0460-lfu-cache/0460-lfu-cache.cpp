/*
Most Important Comments to Remember
keyNode      : key -> node

freqList     : freq -> DLL

minFreq      : smallest frequency currently present

get():
    increase frequency

put():
    existing key -> update + increase frequency

    new key:
        if full -> remove LRU node from minFreq DLL
        insert with freq = 1

LFU eviction: if tie freq
    freqList[minFreq]->tail->prev , LRU

    Go to the DLL having the minimum frequency,
    and remove the Least Recently Used node from that DLL.
*/

class Node {
public:
    int key, val, cnt; // key, value, frequency count
    Node* next;
    Node* prev;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1; // every new node starts with frequency 1
        next = NULL;
        prev = NULL;
    }
};

class List {
public:
    int size; // number of real nodes in DLL
    Node* head;
    Node* tail;

    List() {
        size = 0;

        // dummy head and tail nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        // insert node right after head (MRU position)

        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node* node) {
        // remove node from DLL in O(1)

        Node* delPrev = node->prev;
        Node* delNext = node->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

        size--;
    }
};

class LFUCache {
public:

    map<int, Node*> keyNode;   // key -> node
    map<int, List*> freqList;  // frequency -> DLL

    int maxSizeCache; // capacity
    int minFreq;      // minimum frequency currently present
    int curSize;      // current number of nodes

    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node) {

        // remove old mapping temporarily
        keyNode.erase(node->key);

        // remove node from current frequency list
        freqList[node->cnt]->removeNode(node);

        // if current frequency was minFreq and list became empty
        // then increase minFreq
        if(node->cnt == minFreq &&
           freqList[node->cnt]->size == 0) {
            minFreq++;
        }

        // get list for next higher frequency
        List* nextHigherFreqList = new List();

        if(freqList.find(node->cnt + 1) != freqList.end()) {
            nextHigherFreqList = freqList[node->cnt + 1];
        }

        // increase frequency
        node->cnt += 1;

        // add node to front of new frequency list
        nextHigherFreqList->addFront(node);

        // update maps
        freqList[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {

        // key not found
        if(keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];

        int ans = node->val;

        // increase frequency and move node
        updateFreqListMap(node);

        return ans;
    }


    void put(int key, int value) {

        // edge case: capacity = 0
        if(maxSizeCache == 0)
            return;

        // key already exists
        if(keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            // update value
            node->val = value;

            // increase frequency
            updateFreqListMap(node);

            return;
        }

        // cache full
        if(curSize == maxSizeCache) {

            // get DLL having minimum frequency
            List* list = freqList[minFreq];

            // LRU node of that frequency is just before tail
            Node* nodeToDelete = list->tail->prev;

            // remove from key map
            keyNode.erase(nodeToDelete->key);

            // remove from DLL
            list->removeNode(nodeToDelete);

            curSize--;
        }

        // inserting new node
        curSize++;

        // every new node has frequency = 1
        minFreq = 1;

        List* listFreqOne = new List();

        // reuse freq=1 list if already present
        if(freqList.find(minFreq) != freqList.end()) {
            listFreqOne = freqList[minFreq];
        }

        Node* node = new Node(key, value);

        // insert at front of freq=1 DLL
        listFreqOne->addFront(node);

        // update maps
        keyNode[key] = node;
        freqList[minFreq] = listFreqOne;
    }
};