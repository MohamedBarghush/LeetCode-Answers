class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result; // the final result
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> minHeap;
        
        minHeap.push({nums1[0] + nums2[0], 0, 0});
        int n = nums1.size(), m = nums2.size();

        while (k-- && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            result.push_back({nums1[i], nums2[j]});
            minHeap.pop();

            if (j == 0 && i+1 < n) minHeap.push({nums1[i+1]+nums2[j], i+1, j});
            if (j + 1 < m) minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
        }

        return result;
    }
};