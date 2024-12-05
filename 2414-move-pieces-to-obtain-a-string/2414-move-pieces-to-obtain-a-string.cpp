class Solution {
public:
    bool canChange(string start, string target) {
        string case1, case2;

        for (char c : start) if (c != '_') case1 += c;
        for (char c : target) if (c != '_') case2 += c;

        if (case1 != case2) return false; // matching

        int case1_idx = 0, case2_idx = 0;
        for (int i = 0; i < start.length(); i++) {
            if (start[i] == 'L' || start[i] == 'R') {
                while (start[case1_idx] == '_') ++case1_idx;

                while (target[case2_idx] == '_') ++case2_idx;

                if (start[case1_idx] == 'L' && case1_idx < case2_idx) return false;
                if (start[case1_idx] == 'R' && case1_idx > case2_idx) return false;

                ++case1_idx;
                ++case2_idx;
            }
        }

        return true;
    }
};