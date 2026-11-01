/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        // if (fast == nullptr || fast->next == nullptr) {
        //     return nullptr;
        // }

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};