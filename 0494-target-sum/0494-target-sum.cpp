class Solution {
public:
    int dp (vector<int>& nums, int target, unordered_map<string, int>& memo, int index, int currSum) {
        if (nums.size() == index) return (currSum == target ? 1 : 0);

        string key = to_string(index) + "," + to_string(currSum);
        if (memo.find(key) != memo.end())
            return memo[key];

        int pos = dp(nums, target, memo, index + 1, currSum + nums[index]);
        int neg = dp(nums, target, memo, index + 1, currSum - nums[index]);

        memo[key] = pos + neg;

        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return dp(nums, target, memo, 0, 0);
    }
};