class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls;
        unordered_map<int, unordered_set<int>> colors;
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (balls.count(ball)) {
                int oldColor = balls[ball];
                colors[oldColor].erase(ball);
                if (colors[oldColor].empty()) {
                    count--;
                }
            }

            balls[ball] = color;
            if (colors[color].empty())
                count++;
            colors[color].insert(ball);

            ans.push_back(count);
        }

        return ans;
    }
};