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
    ListNode* reverse(ListNode* head, ListNode* slow) {
        if (head->next == nullptr)
            return head;

        ListNode *prev = nullptr, *cur = head, *nexty = head->next;

        while (cur != slow) {
            nexty = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nexty;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        ListNode *slow = head, *fast = head;

        while (slow->next != nullptr && fast != nullptr &&
               fast->next != nullptr) {
            // len++;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2;

        if (fast == nullptr) {
            head2 = slow;
        }

        else {
            head2 = slow->next;
        }

        ListNode* head1 = reverse(head, slow);

        while (head2 != nullptr && head1 != nullptr) {
            if (head1->val != head2->val)
                return false;

            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};