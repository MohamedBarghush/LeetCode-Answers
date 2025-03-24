class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int currEnd = meetings[0][1];
        int freeDays = meetings[0][0]-1;
        for (int i = 0; i < meetings.size(); i++) {
            if (meetings[i][0] > currEnd) {
                freeDays += (meetings[i][0] - currEnd)-1;
            }
            currEnd = max(currEnd, meetings[i][1]);
        }

        return freeDays + (days - currEnd);
    }
};