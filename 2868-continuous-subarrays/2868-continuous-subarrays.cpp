class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> window;
        int left = 0;
        long long totalSubarrays = 0;

        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);

            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                ++left;
            }

            totalSubarrays += (right - left + 1);
        }

        return totalSubarrays;
    }
};