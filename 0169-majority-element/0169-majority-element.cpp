class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> frequencies;
        int mostVal = -1;
        for (int i = 0; i < nums.size(); i++) {
            frequencies[nums[i]]++;

            if (frequencies[mostVal] < frequencies[nums[i]]) mostVal = nums[i];
        }
        return mostVal;
    }
};