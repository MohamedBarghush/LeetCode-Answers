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
    TreeNode* finalArray(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = finalArray(nums, left, mid - 1);
        root->right = finalArray(nums, mid + 1, right);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Build it by dividing and conquering
        return finalArray(nums, 0, nums.size()-1);
    }
};