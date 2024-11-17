class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // if end is near

        unordered_set<int> hash_set(nums.begin(), nums.end());
        int longest = 0;

        for (int num : hash_set) {
            if (hash_set.find(num - 1) != hash_set.end()) continue;
            
            int currentNum = num;
            int length = 1;

            while (hash_set.find(++currentNum) != hash_set.end()) length++;

            longest = max(longest, length);
        }
        return longest;
    }
};