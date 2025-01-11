class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        int odd = 0;
        unordered_map<char, int> frequency;
        for (char c : s)
            frequency[c]++;

        for (const auto& pair : frequency)
            if (pair.second % 2 == 1) odd++;


        return odd <= k;
    }
};