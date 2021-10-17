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
public:
    int result = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if (root) {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return result;
    }
    void dfs(TreeNode *root, int targetSum) {
        if (root) {
            if (root->val == targetSum) {
                result++;
            }
            dfs(root->left, targetSum - root->val);
            dfs(root->right, targetSum - root->val);
        }
    }
};