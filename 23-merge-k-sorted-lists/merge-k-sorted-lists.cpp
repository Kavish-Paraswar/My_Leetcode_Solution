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

        if (n == 0)
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (ListNode* head : lists) {
            if (head)
                pq.push(head);
        }

        ListNode* tail = new ListNode(0);
        ListNode* head = tail;

        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = cur;

            if (cur->next)
                pq.push(cur->next);
        }

        tail->next = nullptr;

        return head->next;
    }
};