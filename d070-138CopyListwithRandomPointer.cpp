/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node *curr = head;
        int t = 0;
        while (curr) {
            Node *node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        Node *cpy = head->next;
        curr = head;
        
        while (curr) {
            Node *next = curr->next;
            curr->next = next->next;
            if (next->next) next->next = next->next->next;
            curr = curr->next;
        }
        
        return cpy;
    }
};