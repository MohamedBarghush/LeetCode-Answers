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
    int traverse_tree (TreeNode* node) {
        if (node == nullptr) return 0;
        int leftCount = traverse_tree(node->left);
        int rightCount = traverse_tree(node->right);
        return max(leftCount, rightCount) + 1;
    }
    int maxDepth(TreeNode* root) {
        return traverse_tree(root);
    }
};