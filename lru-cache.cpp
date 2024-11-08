#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *next;
    Node *prev;
    int val;

    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int count;
    unordered_map<int, int> vals;
    unordered_map<int, Node *> nodes;
    Node *head = nullptr;
    Node *tail = nullptr;

    void update_recent(int key) {
        Node *node = nodes[key];

        if (node == tail)
            return;
        if (node == head) {
            node->next->prev = nullptr;
            head = node->next;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = nullptr;
        tail->next = node;
        node->prev = tail;

        tail = node;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        count = 0;
    }

    int get(int key) {
        if (vals.find(key) == vals.end())
            return -1;

        update_recent(key);

        return vals[key];
    }

    void put(int key, int value) {
        if (vals.find(key) != vals.end()) {
            vals[key] = value;

            update_recent(key);

            return;
        }

        if (count < capacity) {
            count++;
            vals[key] = value;

            Node *new_node = new Node(key);

            if (!head && !tail) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }

            nodes[key] = new_node;

            return;
        }

        int lru_key = head->val;

        vals.erase(vals.find(lru_key));
        nodes.erase(nodes.find(lru_key));

        vals[key] = value;
        head->val = key;
        nodes[key] = head;

        if (count < 2)
            return;

        Node *tmp = head->next;
        head->next = nullptr;
        head->prev = tail;
        tail->next = head;
        tail = head;
        head = tmp;
        tmp->prev = nullptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void test() {
}
