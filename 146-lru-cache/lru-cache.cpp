class LRUCache {
public:
    struct Node {
        int key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    map<int, Node*> m;
    Node *head, *tail;
    int capacity;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    void insert(Node* curr) {
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }
        insert(m[key]);
        return m[key]->val;
    }

    void put(int key, int val) {
        if (m.find(key) != m.end()) {

            Node* temp = m[key];
            temp->val = val;
            insert(temp);
            return;
        }

        Node* curr = new Node(key, val);
        insert(curr);
        m[key] = curr;
        if (m.size() > capacity) {
            Node* temp = tail->prev;
            temp->prev->next = tail;
            tail->prev = temp->prev;
            m.erase(temp->key);
            delete temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,val);
 */