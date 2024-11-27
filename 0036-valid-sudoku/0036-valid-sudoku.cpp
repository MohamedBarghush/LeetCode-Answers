class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Single array to track constraints
        int seen[27][9] = {0}; // 9 rows + 9 columns + 9 cubes, each with digits 1-9

        for (int row = 0; row < 9; row++) {
            for (int column = 0; column < 9; column++) {
                char current = board[row][column];
                if (current == '.') continue;

                int num = current - '1'; // Convert '1'-'9' to 0-8
                int cubeIndex = (row / 3) * 3 + (column / 3);

                // Check row, column, and cube constraints
                if (seen[row][num] || seen[9 + column][num] || seen[18 + cubeIndex][num]) {
                    return false;
                }

                // Mark the constraints
                seen[row][num] = 1;           // Row constraint
                seen[9 + column][num] = 1;    // Column constraint
                seen[18 + cubeIndex][num] = 1; // Cube constraint
            }
        }

        return true; // All checks passed
    }
};