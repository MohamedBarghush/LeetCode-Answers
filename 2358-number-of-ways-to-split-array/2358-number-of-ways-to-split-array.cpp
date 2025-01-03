class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 0;
        for (int i = 0; i < n; i++)
            prefix += nums[i];

        int count = 0;
        long long sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += nums[i];
            if (sum >= (prefix - sum)) count ++;
        }

        return count;
    }
};