class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> frequencies;
        int most = -1;
        for (int i = 0; i < nums.size(); i++) {
            frequencies[nums[i]]++;

            if (frequencies[most] < frequencies[nums[i]]) most = nums[i];
        }
        return most;
    }
};