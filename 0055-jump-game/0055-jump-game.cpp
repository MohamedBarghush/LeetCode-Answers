class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int powerRemaining = 0;
        bool result = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && powerRemaining == 0 && i != nums.size()-1) {
                result = false;
                break;
            }
            if (nums[i] > powerRemaining) {
                powerRemaining = nums[i];
            }
            powerRemaining--;
        }
        return result;
    }
};