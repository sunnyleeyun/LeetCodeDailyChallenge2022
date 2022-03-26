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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto l : lists) {
            if (l) q.push(l);
        }
        ListNode dummy(-1);
        ListNode* node = &dummy;
        while (!q.empty()) {
            ListNode *top = q.top();
            q.pop();
            node->next = top;
            node = node->next;
            if (top->next) q.push(top->next);   
        }
        return dummy.next;
    }
    struct compare {
        bool operator() (const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };
};