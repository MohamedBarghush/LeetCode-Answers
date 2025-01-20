class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int n = arr.size();
        vector<pair<int, int>> realIndices(n); // <num, row, col>

        // preprocess
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                realIndices[mat[i][j]-1] = {i, j};

        int* rowFreq = new int[rows]{0};
        int* columnFreq = new int[cols]{0};
        // iterate over arr, and increment rows and columns frequencies
        for (int i = 0; i < n; i++) {
            auto& [r,c] = realIndices[arr[i]-1];
            if (++rowFreq[r] == cols) return i;
            if (++columnFreq[c] == rows) return i;
        }

        return 0;
    }
};