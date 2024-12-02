class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;
        int p1=0, p2=0;
        unordered_map<char, int> charCount;
        while (p2 < s.length()) {
            charCount[s[p2]]++;
            
            while (charCount[s[p2]] > 1) {
                charCount[s[p1]]--;
                p1++;
            }

            maxCount = max(maxCount, p2 - p1 + 1);

            p2++;
        }

        return maxCount;
    }
};