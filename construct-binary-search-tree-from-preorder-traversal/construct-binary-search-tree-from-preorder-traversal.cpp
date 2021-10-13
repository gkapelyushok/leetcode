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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorder(preorder, i, INT_MAX);
    }

    TreeNode* bstFromPreorder(vector<int>& preorder, int &i, int max) {
        if (i >= preorder.size() || preorder[i] > max) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = bstFromPreorder(preorder, i, node->val);
        node->right = bstFromPreorder(preorder, i, max);
        return node;
    }
};