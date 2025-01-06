class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        
        int b_l = 0, b_r = 0;
        int m_l = 0, m_r = 0;

        for (int i = 0; i < n; i++) {
            ans[i] += m_l;
            b_l += boxes[i] - '0';
            m_l += b_l;


            int j = n - 1 - i;
            ans[j] += m_r;
            b_r += boxes[j] - '0';
            m_r += b_r;
        }

        return ans;
    }
};