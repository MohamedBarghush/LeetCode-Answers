class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int *count_r = new int[m]{0};
        int *count_c = new int[n]{0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count_r[i]+=grid[i][j];
                count_c[j]+=grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && (count_r[i] > 1 || count_c[j] > 1)) ans++;
            }
        }

        return ans;
    }
};