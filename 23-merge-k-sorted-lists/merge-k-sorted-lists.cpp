/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        const bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (int i = 0; i < n; i++) {
            ListNode* head = lists[i];
            if (head)
                pq.push(head);
        }

        ListNode* tail = new ListNode(0);
        ListNode* start = tail;

        while (!pq.empty()) {
            ListNode* front = pq.top();
            pq.pop();

            tail->next = front;
            tail = front;
            if (front->next != nullptr)
                pq.push(front->next);
        }

        tail->next = nullptr;

        return start->next;
    }
};