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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head, *kth1 = nullptr, *kth2 = head;
        while (--k) {
            cur = cur->next;
        }
        kth1 = cur;
        cur = cur->next;
        while (cur) {
            cur = cur->next;
            kth2 = kth2->next;
        }
        swap(kth1->val, kth2->val);
        return head;
    }
};