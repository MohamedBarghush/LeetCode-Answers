class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n, 1e6);
        steps[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (steps[i] == 1e6) continue;
            int u = 0;
            while (u <= nums[i] && i+u < nums.size()) {
                steps[i+u] = min(steps[i+u], steps[i]+1);
                u++;
            }
        }

        return steps[n-1];
    }
};