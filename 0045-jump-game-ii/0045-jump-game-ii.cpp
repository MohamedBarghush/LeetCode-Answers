class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n, 1e6);
        steps[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (steps[i] == 1e6) continue;
            int u = 0;
            for (int u = 0; u <= nums[i] && i+u < n; u++)
                steps[i+u] = min(steps[i+u], steps[i]+1);
        }

        return steps[n-1];
    }
};