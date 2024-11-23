class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> new_intervals;
        new_intervals.push_back(points[0]);
        int size = 0;

        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] <= new_intervals[size][1]) {
                new_intervals[size][0] = max(new_intervals[size][0], points[i][0]);
                new_intervals[size][1] = min(new_intervals[size][1], points[i][1]);
            } else {
                new_intervals.push_back(points[i]);
                size++;
            }
        }

        return new_intervals.size();
    }
};