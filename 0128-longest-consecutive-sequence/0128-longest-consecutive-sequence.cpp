class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return 1;
        sort(nums.begin(), nums.end());
        int count = 1, longest = 1;

        for (int i = 1; i < nums.size(); i++) {
            cout << "num is: " << nums[i] << endl;
            if (nums[i] == (nums[i-1]+1)) {
                count++;
                if (count > longest) longest = count;
            } else if (nums[i] == nums[i-1]) {} else {
                count = 1;
            }
        }
        return longest;
    }
};