class Solution {
public:
    bool canChange(string start, string target) {
        int case1_idx = 0, case2_idx = 0;
        int n = start.length();

        while (case1_idx < n || case2_idx < n) {
            while (case1_idx < n && start[case1_idx] == '_') ++case1_idx;
            while (case2_idx < n && target[case2_idx] == '_') ++case2_idx;

            if ((case1_idx < n) != (case2_idx < n)) return false;

            if (case1_idx < n && case2_idx < n)

            if (case1_idx < n && case2_idx < n) {
                if (start[case1_idx] != target[case2_idx]) return false;
                if (start[case1_idx] == 'L' && case1_idx < case2_idx) return false;
                if (start[case1_idx] == 'R' && case1_idx > case2_idx) return false;
            }

            ++case1_idx;
            ++case2_idx;
        }

        return true;
    }
};