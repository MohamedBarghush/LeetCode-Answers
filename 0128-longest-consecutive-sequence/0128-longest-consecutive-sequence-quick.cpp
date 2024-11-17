class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return size;
        sort(nums.begin(), nums.end());
        int count = 1, longest = 1;

        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[i-1]) continue;
            else if (nums[i] == (nums[i-1]+1)) {
                count++;
                if (count > longest) longest = count;
            } else {
                count = 1;
            }
        }
        return longest;
    }
};
