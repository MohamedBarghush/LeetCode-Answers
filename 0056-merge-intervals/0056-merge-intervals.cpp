class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> new_intervals;
        std::sort(intervals.begin(), intervals.end(), 
        [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        new_intervals.push_back(intervals[0]);
        int n = intervals.size();
        int size = 0;

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= new_intervals[size][1] 
                && intervals[i][0] >= new_intervals[size][0]) {
                new_intervals[size][0] = min(intervals[i][0], new_intervals[size][0]);
                new_intervals[size][1] = max(intervals[i][1], new_intervals[size][1]);
            } else {
                new_intervals.push_back(intervals[i]);
                size++;
            }
        }
        
        return new_intervals;
    }
};