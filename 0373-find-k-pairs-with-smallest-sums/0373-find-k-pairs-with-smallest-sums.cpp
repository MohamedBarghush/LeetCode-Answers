class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty() || k <= 0) return {};

        vector<vector<int>> result;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap; // use a complicated priority queue

        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, indices] = minHeap.top();
            minHeap.pop();
            int i = indices.first, j = indices.second;

            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return result;
    }
};