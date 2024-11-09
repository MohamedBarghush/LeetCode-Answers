class Solution {
public:
    int binary_search(const std::vector<int>& nums, int first, int target, int min, int max) {
        if (min > max)
            return -1;
        int mid = min + (max - min) / 2;
        int sum = nums[mid] + nums[first];
        
        if (sum == target) {
            return mid;
        } else if (sum > target) {
            return binary_search(nums, first, target, min, mid - 1);
        } else {
            return binary_search(nums, first, target, mid + 1, max);
        }
    }

    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int first = 0;
        while (first < numbers.size() - 1) {
            int result = binary_search(numbers, first, target, first + 1, numbers.size() - 1);
            if (result != -1) {
                return {first + 1, result + 1};
            }
            first++;
        }
        return {};
    }
};