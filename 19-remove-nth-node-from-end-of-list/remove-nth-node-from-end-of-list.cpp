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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)
            return nullptr;

        ListNode *slow = head, *fast = head;

        while (n > 0) {
            fast = fast->next;
            n--;
        }

        ListNode* prev = nullptr;

        while (fast != nullptr) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev == nullptr) {
            head = head->next;
            return head;
        }

        prev->next = slow->next;
        slow->next = nullptr;

        return head;
    }
};