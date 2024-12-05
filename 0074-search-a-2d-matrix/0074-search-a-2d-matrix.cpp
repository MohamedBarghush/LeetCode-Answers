class Solution {
public:
    bool binary_search (vector<vector<int>>& matrix, int m, int n, int min, int max, int target) {
        if (min > max) return false;

        int mid = min + (max - min) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            return binary_search(matrix, m, n, mid + 1, max    , target);
        } else {
            return binary_search(matrix, m, n, min    , mid - 1, target);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        return binary_search(matrix, m, n, 0, m*n-1, target);
    }
};