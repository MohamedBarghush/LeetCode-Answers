class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int positiveCount = 0, negativeCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                negativeCount++;
            else if (nums[i] > 0)
                positiveCount++;
        }

        return max(negativeCount, positiveCount);
    }
};