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
    int xParent;
    int yParent;
    int xDepth;
    int yDepth;
    bool isCousins(TreeNode* root, int x, int y) {
        isCousins(root, x, y, 0, -1);
        return xParent != yParent && xDepth == yDepth;
    }
    void isCousins(TreeNode *root, int x, int y, int depth, int parent) {
        if (!root) {
            return;
        }
        if (root->val == x) {
            xParent = parent;
            xDepth = depth;
        }
        if (root->val == y) {
            yParent = parent;
            yDepth = depth;
        }
        isCousins(root->left, x, y, depth + 1, root->val);
        isCousins(root->right, x, y, depth + 1, root->val);
    }
};