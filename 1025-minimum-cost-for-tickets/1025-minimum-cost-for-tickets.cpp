class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days[days.size() - 1];
        vector<int> dp(n + 1, 0);

        int i = 0;
        for (int j = 1; j <= n; j++) {
            if (j < days[i]) {
                dp[j] = dp[j - 1];
            } else {
                i++;
                dp[j] = min({
                    dp[j - 1] + costs[0],
                    dp[max(0, j - 7)] + costs[1],
                    dp[max(0, j - 30)] + costs[2]
                });
            }
        }

        return dp[n];
    }
};