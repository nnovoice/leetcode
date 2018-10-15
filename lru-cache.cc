#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class LRUCache {
    struct KeyNode {
        int key;
        KeyNode* next;
        KeyNode* prev;

        KeyNode(int k) { 
            key = k; 
            next = prev = nullptr; 
        }
        int getKey() { return key; }
    };
    
    KeyNode* head, *tail;
    unordered_map<int, int> elems;
    unordered_map<int, KeyNode*> keyNodeMap;
    int _capacity;

public:
    LRUCache(int capacity) {
        head = tail = nullptr;
        _capacity = capacity;
        
        // just a beacon node that keeps the logic simple!
        head = new KeyNode(-32767);
        tail = head;
    }
    
    int get(int key) {
        if (elems.find(key) != elems.end()) {
            cout << "found key= " << key << " value=" << elems[key] << endl;
            moveNodeToTail(keyNodeMap[key]);
            cout << "get "; printNodes();
            return elems[key];
        }
        cout << "did not find key=" << key << endl;
        return -1;
    }
    
    void put(int key, int value) {
        if (_capacity == elems.size()) {
            removeLRUKey();
        }

        KeyNode* node = (elems.find(key) != elems.end()) ? keyNodeMap[key] : new KeyNode(value);
        
        moveNodeToTail(node);

        elems[key] = value;
        keyNodeMap[key] = node;

        cout << "put "; printNodes();
    }

    void moveNodeToTail(KeyNode* node) {
        if (node == tail) return;

        if (node == head->next) {
            head->next == node->next;
            node->next->prev = head;

        } else if (node->prev != nullptr) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
        tail->next = nullptr;
    }

    void removeLRUKey() {
        KeyNode* node = head->next;
        if (node == nullptr) return;
        head->next = node->next;
        int key = node->key;
        cout << "removing key= " << key << endl;
        elems.erase(key);
        keyNodeMap.erase(key);
        delete node;
    }

    void printNodes() {
        KeyNode* t = head->next;
        while (t != nullptr) {
            cout << t->key << " ";
            t = t->next;
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
void test0() {
    LRUCache* pCache = new LRUCache( 2 /* capacity */ );

    pCache->put(1, 1);
    pCache->put(2, 2);
    assert(1 == pCache->get(1));       // returns 1
    pCache->put(3, 3);                 // evicts key 2
    assert(-1 == pCache->get(2));      // returns -1 (not found)
    pCache->put(4, 4);                 // evicts key 1
    assert(-1 == pCache->get(1));      // returns -1 (not found)
    assert(3 == pCache->get(3));       // returns 3
    assert(4 == pCache->get(4));       // returns 4*/
}

void test1() {
    LRUCache* pCache = new LRUCache( 4 /* capacity */ );

    pCache->put(1, 1);
    pCache->put(2, 2);
    assert(1 == pCache->get(1));
    pCache->put(3, 3);          
    assert(2 == pCache->get(2));
    pCache->put(4, 4);           
    assert(1 == pCache->get(1)); 
    assert(3 == pCache->get(3)); 
    assert(4 == pCache->get(4)); 
}

void test2() {
    LRUCache* pCache = new LRUCache(4);

    pCache->put(1, 1);
    pCache->put(2, 2);
    assert(1 == pCache->get(1));
    pCache->put(3, 3);          
    assert(2 == pCache->get(2));
    pCache->put(4, 4);           
    assert(1 == pCache->get(1)); 
    assert(3 == pCache->get(3)); 
    assert(4 == pCache->get(4)); 
    pCache->put(5,5);
    assert(-1 == pCache->get(2));
    cout << pCache->get(5);
    assert(5 == pCache->get(5));
}

void test3() {
    LRUCache* pCache = new LRUCache(4);

    pCache->put(1, 1);
    pCache->put(2, 2);
    assert(1 == pCache->get(1));
    pCache->put(3, 3);          
    assert(2 == pCache->get(2));
    pCache->put(4, 4);           
    assert(1 == pCache->get(1)); 
    assert(3 == pCache->get(3)); 
    assert(4 == pCache->get(4)); 
    pCache->put(5,5);
    assert(-1 == pCache->get(2));
    cout << pCache->get(5);
    assert(5 == pCache->get(5));
    assert(4 == pCache->get(4)); 
    assert(4 == pCache->get(4)); 
    assert(1 == pCache->get(1)); 
    pCache->put(5,5);
    assert(3 == pCache->get(3)); 
    assert(5 == pCache->get(5));
    assert(4 == pCache->get(4)); 
    assert(4 == pCache->get(4)); 
    assert(1 == pCache->get(1)); 
    pCache->put(0, 0);
    assert(-1 == pCache->get(3)); 
    assert(0 == pCache->get(0)); 
}

int main() {
    test0();
    test1();
    test2();
    test3();
    return 0;
}