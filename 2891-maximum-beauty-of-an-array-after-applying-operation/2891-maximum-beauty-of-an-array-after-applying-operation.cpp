class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> freq_changes;

        for (int num : nums) {
            freq_changes[num - k]++;
            freq_changes[num + k + 1]--;
        }

        int max_beauty = 0;
        int current_freq = 0;

        for (auto& [key, change] : freq_changes) {
            current_freq += change;
            max_beauty = max(max_beauty, current_freq);
        }

        return max_beauty;
    }
};