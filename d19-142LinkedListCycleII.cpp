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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *first = head, *second = head, *entry = head;
        while (first->next && first->next->next) {
            first = first->next->next;
            second = second->next;
            if (first == second) {
                while (entry != second) {
                    entry = entry->next;
                    second = second->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};