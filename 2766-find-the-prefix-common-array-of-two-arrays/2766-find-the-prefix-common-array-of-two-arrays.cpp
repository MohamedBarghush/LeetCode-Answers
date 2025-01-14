class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(55, 0);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            freq[B[i]]++;
            int count = 0;
            for (int j = 0; j < 55; j++) {
                if (freq[j] == 2) count++;
            }
            ans[i] = count;
        }

        return ans;
    }
};