class Solution {
public:
    int binary_search(vector<int>& nums, int left, int right, int max_ops) {
        if (left == right)
            return left;

        int mid = left + (right - left) / 2;
        int ops = 0;
        for (int n : nums)
            ops += (n-1) / mid;
        
        if (ops <= max_ops) {
            return binary_search(nums, left, mid, max_ops);
        } else {
            return binary_search(nums, mid + 1, right, max_ops);
        }
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        return binary_search(nums, 1, *max_element(nums.begin(), nums.end()), maxOperations);
    }
};