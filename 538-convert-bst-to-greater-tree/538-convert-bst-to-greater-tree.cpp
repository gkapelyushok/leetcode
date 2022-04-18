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
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }
    
    void convert(TreeNode* root) {
        if (!root) {
            return;
        }
        convert(root->right);
        root->val += sum;
        sum = root->val;
        convert(root->left);
    }
    
    int sum = 0;
};