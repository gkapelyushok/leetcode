/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        while (cur) {
            if (cur->child) {
                Node *next = cur->next;
                cur->next = flatten(cur->child);
                cur->child = nullptr;
                cur->next->prev = cur;
                while (cur->next) {
                    cur = cur->next;
                }
                cur->next = next;
                if (next) {
                    cur->next->prev = cur;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};