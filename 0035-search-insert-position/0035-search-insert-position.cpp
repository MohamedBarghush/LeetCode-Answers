class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // iterative binary search implementation
        int min = 0, max = nums.size()-1;
        int mid;
        while (min <= max) {
            mid = min + (max-min) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
                max = mid-1;
                continue;
            } else {
                min = mid+1;
                continue;
            }
        }
        return min + (max-min) / 2;
    }
};