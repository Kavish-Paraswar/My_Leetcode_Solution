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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;

        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        ListNode *head1 = list1, *head2 = list2;
        ListNode* tail;

        if (list1->val < list2->val) {
            tail = head1;
            head1 = head1->next;
        } else {
            tail = head2;
            head2 = head2->next;
        }
        ListNode* start = tail;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }

        if (head1)
            tail->next = head1;

        if (head2)
            tail->next = head2;

        return start;
    }
};