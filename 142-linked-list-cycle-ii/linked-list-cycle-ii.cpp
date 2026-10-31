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
        unordered_set<ListNode*> seen;

        ListNode* temp = head;

        while (temp != nullptr) {
            if (seen.count(temp)) {
                return temp;
            }

            seen.insert(temp);
            temp = temp->next;
        }

        return nullptr;
    }
};