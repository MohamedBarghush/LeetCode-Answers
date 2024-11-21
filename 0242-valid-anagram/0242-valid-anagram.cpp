class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> ana_one;
        int size = s.length();
        for (char ch : s)
            ana_one[ch]++;

        for (char s : t) {
            if (ana_one[s] > 0) {
                // cout << "found: " << s << " with count of " << ana_one[s] << endl;
                ana_one[s]--;
                size--;
            }
        }

        return size == 0;
    }
};