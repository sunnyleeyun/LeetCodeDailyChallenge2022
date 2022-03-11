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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *curr = head, *newHead;
        int cnt = 0;
        while (curr) {
            cnt++;
            curr = curr->next;
        }
        k = cnt - (k % cnt);
        if (k == cnt) return head;
        curr = head;
        while (--k) {
            curr = curr->next;
        }
        newHead = curr->next;
        curr->next = NULL;
        curr = newHead;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head;
        return newHead;
    }
};