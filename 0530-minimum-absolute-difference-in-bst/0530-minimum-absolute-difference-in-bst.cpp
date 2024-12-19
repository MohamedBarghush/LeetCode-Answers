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
        TreeNode* prev;
        s.push(root);
        int minVal = 1e5;
        vector<int> vals;

        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();

            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
            for (int i = 0; i < vals.size(); i++) {
                minVal = min(minVal, abs(curr->val - vals[i]));
            }
            vals.push_back(curr->val);
        }

        return minVal;
    }
};