class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> prefix(n, 0);
        vector<bool> ans(q, true);

        for (int j = 0; j < n - 1; j++)
            prefix[j + 1] = prefix[j] + (nums[j] % 2 == nums[j + 1] % 2 ? 1 : 0);

        for (int i = 0; i < q; i++)
            if (prefix[queries[i][1]] - prefix[queries[i][0]] > 0)
                ans[i] = false;

        return ans;
    }
};