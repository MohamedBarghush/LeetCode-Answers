class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> hash_set;
        for (int num : nums) {
            hash_set.insert(num);
        }
        int longest = 0;

        for (int num : hash_set) {
            if (hash_set.find(num - 1) == hash_set.end()) {
                int currentNum = num;
                int length = 1;

                while (hash_set.find(++currentNum) != hash_set.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};