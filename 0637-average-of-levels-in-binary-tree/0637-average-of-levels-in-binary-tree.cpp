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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {}; // base case
        vector<double> avgs;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            long long levelSum = 0;
            int levelSize = bfs.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = bfs.front();
                bfs.pop();

                levelSum += currentNode->val;

                if (currentNode->left) bfs.push(currentNode->left);
                if (currentNode->right) bfs.push(currentNode->right);
            }
            avgs.push_back(((double)levelSum) / levelSize);
        }

        return avgs;
    }
};