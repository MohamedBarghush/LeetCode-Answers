class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) return {0,0};
        int mini = 0, maxi = nums.size()-1;
        int mid, i;
        int result[2];
        while (mini <= maxi) {
            mid = mini + (maxi - mini) / 2;

            if (nums[mid] == target) {
                result[0] = mid; result[1] = mid;
                i = mid;
                while (i >= 0 && nums[mid] == nums[i]) {
                    result[0] = i;
                    i--;
                }
                i = mid;
                while (i < nums.size() && nums[mid] == nums[i]) {
                    result[1] = i;
                    i++;
                }
                return {result[0], result[1]};
            } else if (nums[mid] < target) {
                mini = mid + 1;
                continue;
            } else {
                maxi = mid - 1;
                continue;
            }
        }

        return {-1,-1};
    }
};