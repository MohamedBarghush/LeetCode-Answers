class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vals(n*n, 0);
        vector<int> ans = {0,0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j] - 1;
                if (vals[val] != 0) {
                    ans[0] = val+1;
                }
                vals[val] = 1;
            }
        }

        for (int i = 0; i < n*n; i++) {
            if (vals[i] == 0) {
                ans[1] = i+1;
            }
        }

        return ans;
    }
};