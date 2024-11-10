class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lst; // to the end
        for (int i = 0; i < nums.size(); i++) {
            if (lst.count(nums[i])) {
                if ((i - lst[nums[i]]) <= k)
                    return true;
            }
            lst[nums[i]] = i;
        }
        return false;
    }
};