class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // vertical pass
        sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int cuts = 0, farthest_end = rectangles[0][3], count = rectangles.size();
        for (int i = 1; i < count; i++) {
            // cout << rectangles[i] << endl;
            if (rectangles[i][1] >= farthest_end)
                cuts++;
            farthest_end = max(farthest_end, rectangles[i][3]);
        }

        if (cuts >= 2) return true; else cuts = 0;

        // horizontal pass
        sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        farthest_end = rectangles[0][2];
        for (int i = 1; i < count; i++) {
            if (rectangles[i][0] >= farthest_end) {
                cuts++;
            }
            farthest_end = max(farthest_end, rectangles[i][2]);
        }

        return cuts >= 2;
    }
};