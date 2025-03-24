class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int currEnd = meetings[0][1], n = meetings.size();
        int freeDays = meetings[0][0]-1;
        for (int i = 0; i < n; i++) {
            int first = meetings[i][0], second = meetings[i][1];
            if (first > currEnd) {
                freeDays += (first - currEnd)-1;
            }
            currEnd = max(currEnd, second);
        }

        return freeDays + (days - currEnd);
    }
};