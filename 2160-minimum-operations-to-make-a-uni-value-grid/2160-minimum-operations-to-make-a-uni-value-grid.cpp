class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flatten;
        
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                flatten.push_back(grid[i][j]);

        sort(flatten.begin(), flatten.end());

        int median = flatten.size() / 2, n = flatten.size(), ans = 0;;
        for (int i = 0; i < n; i++) {
            int val = abs(flatten[median] - flatten[i]);
            if (val % x != 0) return -1;
            ans += val / x;
        }

        return ans;
    }
};