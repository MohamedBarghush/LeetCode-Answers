class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int, int> seq;
        for (auto& pairy : nums1)
            seq[pairy[0]] = pairy[1];
        for (auto& pairy : nums2)
            seq[pairy[0]] += pairy[1];

        for (auto& [key, val] : seq)
            ans.push_back({key, val});

        return ans;
    }
};