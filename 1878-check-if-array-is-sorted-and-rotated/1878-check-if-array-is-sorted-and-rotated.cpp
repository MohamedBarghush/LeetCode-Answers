class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i < n) {
            if (nums[i] < nums[i-1]) break;
            i++;
        }

        if (i == n)
            return true;

        i++;

        while (i < n) {
            if ((nums[i] < nums[i-1]) || (nums[i] > nums[0])) return false;
            i++;
        }

        return nums[n-1] <= nums[0];
    }
};