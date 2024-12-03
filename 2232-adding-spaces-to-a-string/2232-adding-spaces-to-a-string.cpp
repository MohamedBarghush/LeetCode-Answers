class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newOne;
        int index = 0;

        for (int i = 0; i < s.length(); i++) {
            if (index < spaces.size() && i == spaces[index]) {
                newOne += ' ';
                index++;
            }
            newOne += s[i];
        }

        return newOne;
    }
};