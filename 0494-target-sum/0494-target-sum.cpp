class Solution {
public:
    int f(int i, int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) { // all base cases
            if (target == 0 && arr[0] == 0)
                return 2;
            if (abs(target - arr[i]) == 0)
                return 1;
            if (target == 0)
                return 1;
            return 0;
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        int take = 0;
        if (target >= arr[i])
            take = f(i - 1, n, target - arr[i], arr, dp);
        int notTake = f(i - 1, n, target, arr, dp);
        return dp[i][target] = take + notTake;
    }
    int findTargetSumWays(vector<int>& arr,int target) {
        int n=arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (target > sum)
            return 0;
        if ((sum - target) % 2 != 0)
            return 0;
        int s = (sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(s + 1, -1));
        return f(n - 1, n, s, arr, dp);
    }
};