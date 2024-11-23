class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end()); // sort first
        vector<vector<int>> new_intervals;
        new_intervals.push_back(points[0]);
        int j = 0;

        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] <= new_intervals[j][1]) {
                new_intervals[j][0] = max(new_intervals[j][0], points[i][0]);
                new_intervals[j][1] = min(new_intervals[j][1], points[i][1]);
            } else {
                new_intervals.push_back(points[i]);
                j++;
            }
        }

        return new_intervals.size();
    }
};