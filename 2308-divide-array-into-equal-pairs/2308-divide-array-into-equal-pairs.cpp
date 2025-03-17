class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int vals[501] = {0};
        bool quty = false;
        for (int i = 0; i < nums.size(); i++)
            vals[nums[i]]++;

        for (int i = 0; i < 501; i++)
            if (vals[i] % 2 == 1) return false;

        return true;
    }
};