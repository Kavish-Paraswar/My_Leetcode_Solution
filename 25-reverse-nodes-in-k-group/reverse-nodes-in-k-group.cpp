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
    ListNode* reverse(ListNode* head, int k) {

        ListNode *prev = nullptr, *cur = head;

        while (cur != nullptr && k > 0) {
            swap(cur->next, prev);
            swap(cur, prev);
            k--;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next == nullptr)
            return head;

        int groups = 0;

        ListNode *temp = head, *org = head;

        while (temp != nullptr) {
            groups++;
            temp = temp->next;
        }

        groups = groups / k;
        ListNode *nexty = head, *last = nullptr;

        for (int i = 0; i < groups; i++) {

            for (int i = 0; i < k; i++) {
                nexty = nexty->next;
            }
            ListNode* tail = head;
            ListNode* temp = reverse(head, k);
            if (i == 0) {
                org = temp;
            } else {
                last->next = temp;
            }

            tail->next = nexty;
            last = tail;
            head = nexty;
        }

        return org;
    }
};