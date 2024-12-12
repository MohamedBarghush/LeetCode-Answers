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
    bool getSum (TreeNode* root, int targetSum, int iterativeSum) {
        if (root == nullptr) 
            return false;

        iterativeSum += root->val;

        if (root->left == nullptr && root->right == nullptr) 
            return iterativeSum == targetSum;

        return getSum(root->left, targetSum, iterativeSum) || getSum(root->right, targetSum, iterativeSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return getSum(root, targetSum, 0);
    }
};