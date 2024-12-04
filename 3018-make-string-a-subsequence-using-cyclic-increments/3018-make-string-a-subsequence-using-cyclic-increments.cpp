class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.length() == 0) return true;
        else {if (str1.length() == 0 || str2.length() > str1.length()) return false;}
        int p1 = 0;
        int p2 = 0;

        while (p1 < str1.length() && p2 < str2.length()) {
            if (p1 >= str1.length()) p1 = 0;
            if (str1[p1] == str2[p2]) {
                p1++;
                p2++;
            } else {
                char nextChar = (str1[p1] == 'z') ? 'a' : str1[p1] + 1;
                if (str2[p2] == nextChar) {
                    p1++;
                    p2++;
                } else {
                    p1++;
                }
            }
        }

        return p2 == str2.length();
    }
};