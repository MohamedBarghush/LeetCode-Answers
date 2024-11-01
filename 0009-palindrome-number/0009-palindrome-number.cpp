class Solution {
public:
    bool isPalindrome(int x) {
        string pal = to_string(x);
        int len = pal.length();
        for (int i = 0; i < len/2; i++) {
            if (pal[i] != pal[len-1-i]) return false;
        }
        return true; 
    }
};