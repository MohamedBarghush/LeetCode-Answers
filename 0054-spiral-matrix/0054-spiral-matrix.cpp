class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int size = n*m;
        vector<int> result;
        vector<pair<int, int>> dir = {
            { 0,  1},
            { 1,  0},
            { 0, -1},
            {-1,  0}
        };
        int direction = 0;

        int row = 0, col = 0;

        for (int i = 0; i < size; i++) {
            result.push_back(matrix[row][col]);
            matrix[row][col] = -101;

            int nextRow = row + dir[direction].first;
            int nextCol = col + dir[direction].second;

            if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && matrix[nextRow][nextCol] != -101) {
                row = nextRow;
                col = nextCol;
            } else {
                direction = (direction + 1) % 4;
                row += dir[direction].first;
                col += dir[direction].second;
            }
        }

        return result;
    }
};