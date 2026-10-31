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
    int pairSum(ListNode* head) {
        if (head->next == nullptr)
            return head->val;

        ListNode *slow = head, *fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *cur = head;

        while (cur != slow) {
            swap(cur->next, prev);
            swap(prev, cur);
        }
        ListNode *head2 = slow, *head1 = prev;

        int ans = 0;

        while (head1 != nullptr) {
            ans = max(ans, head1->val + head2->val);
            // cout << head1->val << " " << head2->val;
            head1 = head1->next;
            head2 = head2->next;
        }

        return ans;
    }
};