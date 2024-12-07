class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lowest = 1, highest = *max_element(nums.begin(), nums.end());
        while (lowest < highest) {
            int mid = lowest + (highest - lowest) / 2;
            int ops = 0;
            for (int n : nums) if ((ops += (n - 1) / mid) > maxOperations) break;
            ops <= maxOperations ? highest = mid : lowest = mid + 1;
        }
        return highest;
    }
};