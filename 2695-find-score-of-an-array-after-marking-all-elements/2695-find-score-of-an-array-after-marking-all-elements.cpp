class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> elements;

        for (int i = 0; i < n; i++)
            elements.emplace_back(nums[i], i);

        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        std::vector<bool> marked(n, false);
        long long score = 0;

        for (const auto& [value, index] : elements) {
            if (!marked[index]) {
                score += value;

                marked[index] = true;
                if (index > 0)
                    marked[index - 1] = true;
                if (index < n - 1)
                    marked[index + 1] = true;
            }
        }

        return score;
    }
};