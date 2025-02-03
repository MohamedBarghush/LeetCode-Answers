class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        unsigned char longest = 1, inc = 1, dec = 1;
        unsigned char n = nums.size();
        for (unsigned char i = 1; i < n; i++) {
            inc = (nums[i] > nums[i - 1]) ? inc + 1 : 1;
            dec = (nums[i] < nums[i - 1]) ? dec + 1 : 1;

            longest = max({longest, inc, dec});
        }
        return longest;
    }
};