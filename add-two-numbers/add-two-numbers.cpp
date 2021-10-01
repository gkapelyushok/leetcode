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
        ListNode *it = new ListNode(), *result = it;
        int prev = 0;
        while (l1 || l2 || prev) {
            int num1 = 0, num2 = 0;
            if (l1) {
                num1 = l1->val;
            }
            if (l2) {
                num2 = l2->val;
            }
            int sum = num1 + num2 + prev;
            it->next = new ListNode(sum % 10);
            it = it->next;
            prev = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return result->next;
    }
};