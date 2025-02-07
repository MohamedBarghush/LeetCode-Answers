class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int count = 0, n = queries.size();
        unordered_map<int, int> balls, colors;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (balls.count(ball)) {
                int oldColor = balls[ball];
                colors[oldColor]--;
                if (colors[oldColor] == 0)
                    colors.erase(oldColor);
            }

            balls[ball] = color;
            colors[color]++;

            ans[i] = colors.size();
        }

        return ans;
    }
};