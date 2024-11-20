class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int remain = 0; // rest of the code

        for (int i = nums.size()-1; i >= 0; i--) {
            remain = target - nums[i];
            if (hash.count(remain) > 0)
                return {hash[remain], i};
            hash[nums[i]] = i;
        }

        return {0,1};
    }
};