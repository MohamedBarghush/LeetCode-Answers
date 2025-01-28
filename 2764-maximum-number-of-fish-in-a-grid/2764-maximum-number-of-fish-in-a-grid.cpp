class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == 0) return 0;

        int out = grid[i][j];

        grid[i][j] = 0;

        out += dfs(i+1, j  , grid);
        out += dfs(i-1, j  , grid);
        out += dfs(i  , j+1, grid);
        out += dfs(i  , j-1, grid);

        return out;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int k = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (grid[i][j] != 0) maxi = max(maxi, dfs(i, j, grid));
            }
        }

        return maxi;
    }
};