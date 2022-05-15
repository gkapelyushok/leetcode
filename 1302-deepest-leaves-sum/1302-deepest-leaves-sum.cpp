/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int level = 0, sum = 0;
    void recursion(TreeNode* root, int cur_level) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            if (cur_level > level) {
                level = cur_level;
                sum = root->val;
            } else if (cur_level == level) {
                sum += root->val;
            }
            return;
        }
        cur_level++;
        recursion(root->left, cur_level);
        recursion(root->right, cur_level);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        recursion(root, 0);
        return sum;
    }
};