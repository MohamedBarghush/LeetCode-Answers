class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        int odd = 0;
        int frequency[26] = {};
        for (char c : s)
            frequency[(c - 'a')]++;

        for (int i : frequency)
            if (i % 2 == 1) odd++;

        return odd <= k;
    }
};