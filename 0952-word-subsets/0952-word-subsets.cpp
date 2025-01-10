class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int frequencies[26] = {};
        int count = 0;
        vector<string> ans;
        for (int i = 0; i < words2.size(); i++) {
            int temp[26] = {};
            for (int j = 0; j < words2[i].length(); j++) {
                int idx = words2[i][j] - 'a';
                temp[idx]++;
                frequencies[idx] = max(frequencies[idx], temp[idx]);
            }
        }
        for (char c : frequencies)
            count += c;

        for (int i = 0; i < words1.size(); i++) {
            int temp[26] = {};
            int tempC = count;
            for (int j = 0; j < words1[i].length(); j++) {
                int c = words1[i][j] - 'a';
                if (temp[c] < frequencies[c]) {
                    temp[c]++;
                    tempC--;
                }
                if (tempC == 0) break;
            }
            if (tempC == 0)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};