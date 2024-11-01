class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magLetters;
        for (char ch : magazine) magLetters[ch]++;
        for (char ch : ransomNote) {
            magLetters[ch]--;
            if (magLetters[ch] < 0) return false;
        }
        return true;
    }
};