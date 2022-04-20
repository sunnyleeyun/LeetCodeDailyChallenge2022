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
    TreeNode* helper(TreeNode* root, TreeNode* tail) {
        if (!root) return tail;
        TreeNode* res = helper(root->left, root);
        root->left = nullptr;
        root->right = helper(root->right, tail);
        return res;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root, nullptr);
    }
};