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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int res = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelValues[i] = node->val;

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            res += getMinSwaps(levelValues);
        }

        return res;
    }

private:
    int getMinSwaps(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++)
            pos[original[i]] = i;

        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) {
                swaps++;

                int curPos = pos[target[i]];
                pos[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }

        return swaps;
    }
};