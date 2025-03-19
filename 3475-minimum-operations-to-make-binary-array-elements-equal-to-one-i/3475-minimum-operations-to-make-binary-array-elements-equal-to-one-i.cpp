class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        for (int i = 0; i < nums.size()-2; i++) {
            if (nums[i] == 0) {
                ops++;
                for (int j = 0; j < 3; j++) {
                    nums[i+j] = !nums[i+j];
                }
            }
        }

        return nums.back() == 0 || nums[nums.size()-2] == 0 ? -1 : ops;
    }
};