class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> hash_set(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (hash_set.find(num - 1) == hash_set.end()) {
                int currentNum = num;
                int length = 1;

                while (hash_set.find(currentNum + 1) != hash_set.end()) {
                    currentNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};