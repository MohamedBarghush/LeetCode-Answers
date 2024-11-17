class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> hash_set(nums.begin(), nums.end());
        int longest = 0, currentNum, length;

        for (int num : hash_set) {
            if (hash_set.find(num - 1) != hash_set.end()) continue;
            
            currentNum = num;
            length = 1;

            while (hash_set.find(++currentNum) != hash_set.end()) length++;

            longest = max(longest, length);
        }
        return longest;
    }
};