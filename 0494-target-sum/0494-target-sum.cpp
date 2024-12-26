class Solution {
public:
    int dp(vector<int>& nums, int target, vector<vector<int>>& memo, int index, int currSum, int offset) {
        if (index == nums.size()) return (currSum == target ? 1 : 0); // base fkin case b****

        if (memo[index][currSum + offset] != -1)
            return memo[index][currSum + offset];

        int pos = dp(nums, target, memo, index + 1, currSum + nums[index], offset);
        int neg = dp(nums, target, memo, index + 1, currSum - nums[index], offset);

        memo[index][currSum + offset] = pos + neg;

        return memo[index][currSum + offset];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum;
        vector<vector<int>> memo(nums.size(), vector<int>(2 * sum + 1, -1));
        return dp(nums, target, memo, 0, 0, offset);
    }
};