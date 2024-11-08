class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        // Reverse the entire array
        std::reverse(nums.begin(), nums.end());

        // Reverse the first k
        std::reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining n - k
        std::reverse(nums.begin() + k, nums.end());
    }
};