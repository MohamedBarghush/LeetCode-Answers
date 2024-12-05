class Solution {
public:
    bool canChange(string start, string target) {
        int right = 0, left = 0;
        int n = target.length();

        for (int i = 0, j = 0; i < n; i++) {
            if (start[i] == 'R') right++;
            if (start[i] == 'L') left++;
            if (target[i] == 'R') right--;
            if (target[i] == 'L') left--;

            if (start[i] != '_') {
                while(j < n && target[j] == '_') j++;
                if (start[i] != target[j]        
                || (start[i] == 'R' && i > j)    // found R but indices fked up
                || (start[i] == 'L' && i < j))   // found L but indices fked up
                    return false;
                j++;
            }
        }

        return (right == 0 && left == 0) ? true : false;
    }
};