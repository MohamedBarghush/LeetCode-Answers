class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> stepsToReach(n, false);
        stepsToReach[n-1] = true;

        for (int i = n - 1; i >= 0; i--) {
            int o = nums[i];
            while (i+o <= n-1 && o >= 0) {
                if (stepsToReach[i+o] == true) {
                    stepsToReach[i] = true;
                    break;
                }
                o--;
            }
        }
        return stepsToReach[0];
    }
};