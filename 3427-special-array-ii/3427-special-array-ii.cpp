class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> invalidIndices;

        for (int j = 0; j < n - 1; j++) {
            if (nums[j] % 2 == nums[j + 1] % 2) {
                invalidIndices.push_back(j);
            }
        }

        vector<bool> answer(q, true);

        for (int i = 0; i < q; i++) {
            auto it = lower_bound(invalidIndices.begin(), invalidIndices.end(), queries[i][0]);

            if (it != invalidIndices.end() && *it <= queries[i][1] - 1)
                answer[i] = false;
        }

        return answer;
    }
};