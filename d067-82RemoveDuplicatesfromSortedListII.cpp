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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *curr = head;
        while (curr) {
            ListNode *next = curr->next, *tmp;
            if (next && curr->val == next->val) {
                while (next && curr->val == next->val) {
                    tmp = next;
                    next = next->next;
                    delete tmp;
                }
                tmp = curr;
                curr = next;
                delete tmp;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy.next;
    }
};