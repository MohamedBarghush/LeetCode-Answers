class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int start = nums[0];
        vector<string> return_list;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != (nums[i-1]+1)) {
                if (start != nums[i-1])
                    return_list.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                else
                    return_list.push_back(to_string(start));
                start = nums[i];
            }
        }

        if (start == nums.back())
            return_list.push_back(to_string(start));
        else
            return_list.push_back(to_string(start) + "->" + to_string(nums.back()));

        return return_list;
    }
};