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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *head = &dummy;
        int rem = 0;
        while (l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int v = v1 + v2 + rem;
            if (v >= 10) {
                v -= 10;
                rem = 1;
            } else rem = 0;
            head->next = new ListNode(v);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            head = head->next;
        }
        if (rem) head->next = new ListNode(rem);
        return dummy.next;
    }
};