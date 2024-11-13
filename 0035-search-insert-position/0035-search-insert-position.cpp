class Solution {
public:
    // recursive
    // int binary_search (vector<int>& nums, int target, int min, int max) {
    //     int mid = min + (max - min) / 2;
    //     if (min > max) return (mid);

    //     if (nums[mid] == target)
    //         return mid;
    //     else if (nums[mid] > target)
    //         return binary_search(nums, target, min, mid-1);
    //     else
    //         return binary_search(nums, target, mid+1, max);
    // }
    int searchInsert(vector<int>& nums, int target) {
        // iterative
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