class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int seen[27][9] = {0}; // single array

        for (int row = 0; row < 9; row++) {
            for (int column = 0; column < 9; column++) {
                char current = board[row][column];
                if (current == '.') continue;

                int num = current - '1';
                int cubeIndex = (row / 3) * 3 + (column / 3);

                if (seen[row][num] || seen[9 + column][num] || seen[18 + cubeIndex][num]) {
                    return false;
                }

                seen[row][num] = 1;
                seen[9 + column][num] = 1;
                seen[18 + cubeIndex][num] = 1;
            }
        }

        return true;
    }
};