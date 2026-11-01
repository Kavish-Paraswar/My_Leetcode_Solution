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

        ListNode* start = (list1->val <= list2->val) ? list1 : list2;
        ListNode* tail = start;
        ListNode *p1 = list1, *p2 = list2;

        if (start == list1) {
            p1 = p1->next;
        } else {
            p2 = p2->next;
        }

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;

            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        tail->next = (p1 != nullptr) ? p1 : p2;
        return start;
    }
};