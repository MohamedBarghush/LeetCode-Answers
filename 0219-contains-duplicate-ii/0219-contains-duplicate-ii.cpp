class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // Use unordered_map to mimic HashMap in Java
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i])) { // Equivalent of containsKey in Java
                if (i - map[nums[i]] <= k)
                    return true;
                map[nums[i]] = i;
            } else {
                map[nums[i]] = i;
            }
        }
        return false;
    }
};