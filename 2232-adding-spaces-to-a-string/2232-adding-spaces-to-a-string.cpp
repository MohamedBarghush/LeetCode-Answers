class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int newLen = s.length() + spaces.size();
        char newOne[newLen]; // pre-allocated chars
        int index = 0, newIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            if (index < spaces.size() && i == spaces[index]) {
                newOne[newIndex++] = ' ';
                index++;
            }
            newOne[newIndex++] = s[i];
        }

        return string(newOne, newLen);
    }
};