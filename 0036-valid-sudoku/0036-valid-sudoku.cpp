class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> columns(9);
        vector<unordered_map<int, int>> rows(9);
        vector<vector<unordered_map<int, int>>> cubes(3, vector<unordered_map<int, int>>(3));

        for (int row = 0; row < 9; row++) {
            for (int column = 0; column < 9; column++) {
                if (board[row][column] == '.') continue;
                if (rows[column].count(board[row][column]) > 0 
                    || columns[row].count(board[row][column]) > 0
                    || cubes[row / 3][column / 3].count(board[row][column]) > 0) {
                    return false;
                } else {
                    rows[column][board[row][column]]++;
                    columns[row][board[row][column]]++;
                    cubes[row / 3][column / 3][board[row][column]]++;
                }
            }
        }

        return true;
    }
};