class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {}; // int array
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string res;
        int currIdx = 25;
        while (currIdx >= 0) {
            if (freq[currIdx] == 0) {
                currIdx--;
                continue;
            }

            int use = min(freq[currIdx], repeatLimit);
            res.append(use, 'a' + currIdx);
            freq[currIdx] -= use;

            if (freq[currIdx] > 0) {
                int smallerCharIndex = currIdx - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0)
                    smallerCharIndex--;

                if (smallerCharIndex < 0)
                    break;

                res.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return res;
    }
};