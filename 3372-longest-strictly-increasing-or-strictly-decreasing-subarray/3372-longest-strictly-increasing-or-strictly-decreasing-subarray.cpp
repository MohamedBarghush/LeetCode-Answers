class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        bool greater = nums[1] > nums[0];
        int counter = 1, longest = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                if (!greater) {
                    greater = true;
                    counter = 2;
                } else counter++;
            } else if (nums[i] > nums[i-1]) {
                if (greater) {
                    greater = false;
                    counter = 2;
                } else counter++;
            } else { 
                counter = 1;
            }
            longest = max(counter, longest);
        }

        return longest;
    }
};