class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1}; // Handle edge case

        int mini = 0, maxi = nums.size() - 1;
        int mid;

        // Find the leftmost index of the target
        int left = -1;
        while (mini <= maxi) {
            mid = mini + (maxi - mini) / 2;
            if (nums[mid] == target) {
                left = mid;
                maxi = mid - 1; // Narrow the range to find the leftmost occurrence
            } else if (nums[mid] < target) {
                mini = mid + 1;
            } else {
                maxi = mid - 1;
            }
        }

        if (left == -1) return {-1, -1}; // If target not found

        // Find the rightmost index of the target
        mini = left; // Start from the leftmost occurrence
        maxi = nums.size() - 1;
        int right = -1;
        while (mini <= maxi) {
            mid = mini + (maxi - mini) / 2;
            if (nums[mid] == target) {
                right = mid;
                mini = mid + 1; // Narrow the range to find the rightmost occurrence
            } else if (nums[mid] < target) {
                mini = mid + 1;
            } else {
                maxi = mid - 1;
            }
        }

        return {left, right};
    }
};