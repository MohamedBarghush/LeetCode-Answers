class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> new_intervals; // new intervals
        sort(intervals.begin(), intervals.end());
        new_intervals.push_back(intervals[0]);
        int n = intervals.size();
        int size = 0;

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= new_intervals[size][1])
                new_intervals[size][1] = max(intervals[i][1], new_intervals[size][1]);
            else {
                new_intervals.push_back(intervals[i]);
                size++;
            }
        }
        
        return new_intervals;
    }
};
