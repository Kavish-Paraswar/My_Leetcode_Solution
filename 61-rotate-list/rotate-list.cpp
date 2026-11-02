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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int len = 0;

        ListNode *org = head, *temp = org;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if (k == 0)
            return head;
        int rotate = len - k;

        ListNode* temp2 = org;

        while (rotate > 1) {
            temp2 = temp2->next;
            rotate--;
        }
        ListNode* rem = temp2->next;
        org = rem;
        temp2->next = nullptr;
        // cout << rem->val;

        while (rem->next != nullptr) {
            rem = rem->next;
        }

        rem->next = head;

        return org;
    }
};