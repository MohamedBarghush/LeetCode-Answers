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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        int minVal = INT_MAX;

        while (!s.empty() || curr != nullptr) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            if (prev != nullptr)
                minVal = min(minVal, abs(curr->val - prev->val));
            prev = curr;

            curr = curr->right;
        }

        return minVal;
    }
};