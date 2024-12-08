class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size(); // max effiency
        sort(events.begin(), events.end());

        vector<int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2];

        for (int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);

        int maxSum = 0, left = 0, right = 0, mid = 0;
        int nextEventIndex = -1;

        for (int i = 0; i < n; i++) {
            left = i + 1;
            right = n - 1;
            nextEventIndex = -1;

            while (left <= right) {
                mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextEventIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nextEventIndex != -1)
                maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);

            maxSum = max(maxSum, events[i][2]);
        }

        return maxSum;
    }
};