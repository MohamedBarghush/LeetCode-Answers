class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        bool streak = true;
        int counter = 1, longest = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) counter++;
            else counter = 1;
            longest = max(counter, longest);
        }

        longest = max(counter, longest);

        counter = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) counter++;
            else counter = 1;
            longest = max(counter, longest);
        }

        return longest;
    }
};