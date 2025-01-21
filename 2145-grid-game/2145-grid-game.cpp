class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long prefix = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long suffix = 0;

        long long ans = 9223372036854775807;
        for (int i = 0; i < n; i++) {
            prefix -= grid[0][i];

            ans = min(ans, max(prefix, suffix));
            suffix += grid[1][i];
        }

        return ans;
    }
};
