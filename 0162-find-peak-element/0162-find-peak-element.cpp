class Solution {
public:
    int binary_search(vector<int>& nums, int min, int max) {
        if (min > max) return -1;

        int mid = min + (max - min) / 2;

        if ((mid == 0 || nums[mid] > nums[mid - 1])
            && (mid == nums.size()-1 || nums[mid] > nums[mid + 1])) {
            return mid;
        }

        if (mid > 0 && nums[mid - 1] > nums[mid])
            return binary_search(nums, min, mid - 1);
        return binary_search(nums, mid + 1, max);
    }
    int findPeakElement(vector<int>& nums) {
        // trivial cases
        if (nums.size() == 1) return 0;
        else if (nums[0] > nums[1]) return 0;
        else if (nums.back() > nums[nums.size() - 2]) return nums.size() - 1;

        return binary_search(nums, 0, nums.size() - 1);
    }
};