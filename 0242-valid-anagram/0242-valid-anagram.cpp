class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> ana_one;
        int size = s.length();
        for (char ch : s)
            ana_one[ch]++;

        for (char ch : t) {
            if (ana_one[ch] > 0) {
                ana_one[ch]--;
                size--;
            }
        }

        return size == 0;
    }
};