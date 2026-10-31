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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *head1 = headA, *head2 = headB;

        if (head1 == NULL || head2 == NULL)
            return NULL;

        while (head1 != nullptr && head2 != nullptr && head1 != head2) {
            head1 = head1->next;
            head2 = head2->next;

            if (head1 == head2)
                return head1;

            if (head1 == nullptr)
                head1 = headB;
            if (head2 == nullptr)
                head2 = headA;
        }

        return head1;
    }
};