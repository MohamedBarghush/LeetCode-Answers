class Solution {
public:
    bool isPalindrome(int x) {
        string pal = to_string(x);
        for (int i = 0; i < pal.length()/2; i++) {
            if (pal[i] != pal[pal.length()-1-i]) return false;
        }
        return true;
    }
};