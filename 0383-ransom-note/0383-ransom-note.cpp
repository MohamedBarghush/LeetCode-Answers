class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magL;
        for (char ch : magazine) magL[ch]++;
        for (char ch : ransomNote) {
            if (magL[ch] <= 0) return false;
            magL[ch]--;
        }
        return 1;
    }
};